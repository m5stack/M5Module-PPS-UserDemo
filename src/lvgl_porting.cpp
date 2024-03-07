#include "lvgl_porting.h"

lv_ui guider_ui;

#define EXAMPLE_LVGL_TICK_PERIOD_MS     2               /*!< LVGL tick period in ms */
#define EXAMPLE_LVGL_TASK_MAX_DELAY_MS  500
#define EXAMPLE_LVGL_TASK_MIN_DELAY_MS  1
#define EXAMPLE_LVGL_TASK_STACK_SIZE    (8 * 1024)
#define EXAMPLE_LVGL_TASK_PRIORITY      2

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf1[LCD_WIDTH * 20];
static lv_color_t buf2[LCD_WIDTH * 20];

static int32_t encoder_diff;
static lv_indev_state_t encoder_state;
uint8_t encoder_test_flag = 0;

SemaphoreHandle_t xGuiSemaphore;

TaskHandle_t task_lvgl_handle    = NULL;

uint8_t page_number = PAGE_STANDBY;

uint8_t btnA_lock_flag = 0;
uint8_t btnB_lock_flag = 0;
uint8_t btnC_lock_flag = 0;

long flash_counter = 0;
uint8_t flash_slow_flag = 0;
uint8_t flash_fast_flag = 0;

bool example_lvgl_lock(int timeout_ms)
{
    const TickType_t timeout_ticks = (timeout_ms == -1) ? portMAX_DELAY : pdMS_TO_TICKS(timeout_ms);
    return xSemaphoreTake(xGuiSemaphore, timeout_ticks) == pdTRUE;
}

void example_lvgl_unlock(void)
{
    xSemaphoreGive(xGuiSemaphore);
}

static void example_lvgl_port_task(void *arg)
{
    uint32_t task_delay_ms = EXAMPLE_LVGL_TASK_MAX_DELAY_MS;
    setup_ui(&guider_ui);
    while (1) {
        /* Lock the mutex due to the LVGL APIs are not thread-safe */
        if (example_lvgl_lock(-1)) {
            M5.update();
            task_delay_ms = lv_timer_handler();
            /* Release the mutex */
            example_lvgl_unlock();
        }
        if (task_delay_ms > EXAMPLE_LVGL_TASK_MAX_DELAY_MS) {
            task_delay_ms = EXAMPLE_LVGL_TASK_MAX_DELAY_MS;
        } else if (task_delay_ms < EXAMPLE_LVGL_TASK_MIN_DELAY_MS) {
            task_delay_ms = EXAMPLE_LVGL_TASK_MIN_DELAY_MS;
        }
        vTaskDelay(pdMS_TO_TICKS(task_delay_ms));
    }
}

/* Display flushing */
static void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    int w = (area->x2 - area->x1 + 1);
    int h = (area->y2 - area->y1 + 1);

    M5.Display.startWrite();                            /* Start new TFT transaction */
    M5.Display.setAddrWindow(area->x1, area->y1, w, h); /* set the working window */

    M5.Display.writePixels((lgfx::rgb565_t *)&color_p->full, w * h);

    M5.Display.endWrite();     /* terminate TFT transaction */
    lv_disp_flush_ready(disp); /* tell lvgl that flushing is done */
}

/*Read the touchpad*/
static void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
    uint16_t touchX, touchY;

    bool touched = M5.Display.getTouch(&touchX, &touchY);

    if (!touched)
    {
        data->state = LV_INDEV_STATE_REL;
    }
    else
    {
        data->state = LV_INDEV_STATE_PR;

        data->point.x = touchX;
        data->point.y = touchY;
    }
}

/*Test if `id` button is pressed or not*/
static bool button_is_pressed(uint8_t id)
{
    if (page_number == PAGE_STANDBY) {
        switch (id)
        {
        case 0:
            if (M5.BtnA.isPressed()){
                return true;
            }
            break;
        case 1:
            if (M5.BtnB.isPressed()){
                return true;
            }
            break;
        case 2:
            if (M5.BtnC.isPressed()){
                return true;
            }
            break;
        
        default:
            break;
        }
    }

    return false;
}

/*Get ID  (0, 1, 2 ..) of the pressed button*/
static int8_t button_get_pressed_id(void)
{
    uint8_t i;

    /*Check to buttons see which is being pressed (assume there are 2 buttons)*/
    for(i = 0; i < 3; i++) {
        /*Return the pressed button's ID*/
        if(button_is_pressed(i)) {
            return i;
        }
    }

    /*No button pressed*/
    return -1;
}

/*Will be called by the library to read the button*/
static void button_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{

    static uint8_t last_btn = 0;

    /*Get the pressed button's ID*/
    int8_t btn_act = button_get_pressed_id();

    if(btn_act >= 0) {
        data->state = LV_INDEV_STATE_PR;
        last_btn = btn_act;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }

    /*Save the last pressed button's ID*/
    data->btn_id = last_btn;
}

/*Get the currently being pressed key.  0 if no key is pressed*/
static uint32_t keypad_get_key(void)
{
    /*Your code comes here*/
    if (page_number == PAGE_RUNNING) {
        if (output_flag == 0) {
            if (M5.BtnA.wasClicked()) {
                beep();
                return 1;
            }
            if (M5.BtnB.wasClicked()) {
                beep();
                return 4;
            }
            if (M5.BtnC.wasClicked()) {
                beep();
                return 3;
            }
            if (!btnA_lock_flag) {
                if (M5.BtnA.isHolding()) {
                    beep();
                    btnA_lock_flag = 1;
                    return 6;
                }
            }
            else {
                if (M5.BtnA.isReleased())
                    btnA_lock_flag = 0;
            }
            if (!btnB_lock_flag) {
                if (M5.BtnB.isHolding()) {
                    beep();
                    btnB_lock_flag = 1;
                    return 7;
                }
            }
            else {
                if (M5.BtnB.isReleased())
                    btnB_lock_flag = 0;
            }
        }
        else if (output_flag == 1) {
            if (M5.BtnA.wasClicked()) {
                beep();
                return 6;
            }
            if (M5.BtnB.wasClicked()) {
                beep();
                return 4;
            }
            if (M5.BtnC.wasClicked()) {
                beep();
                return 3;
            }
            if (!btnA_lock_flag) {
                if (M5.BtnA.isHolding()) {
                    beep();
                    btnA_lock_flag = 1;
                    return 6;
                }
            }
            else {
                if (M5.BtnA.isReleased())
                    btnA_lock_flag = 0;
            }
            if (!btnB_lock_flag) {
                if (M5.BtnB.isHolding()) {
                    beep();
                    btnB_lock_flag = 1;
                    return 1;
                }
            }
            else {
                if (M5.BtnB.isReleased())
                    btnB_lock_flag = 0;
            }
        }
    }
    return 0;
}

/*Will be called by the library to read the mouse*/
static void keypad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint32_t last_key = 0;

    /*Get whether the a key is pressed and save the pressed key*/
    uint32_t act_key = keypad_get_key();
    if(act_key != 0) {
        data->state = LV_INDEV_STATE_PR;

        /*Translate the keys to LVGL control characters according to your key definitions*/
        switch(act_key) {
            case 1:
                act_key = LV_KEY_NEXT;
                break;
            case 2:
                act_key = LV_KEY_PREV;
                break;
            case 3:
                act_key = LV_KEY_LEFT;
                break;
            case 4:
                act_key = LV_KEY_RIGHT;
                break;
            case 5:
                act_key = LV_KEY_ENTER;
                break;
            case 6:
                act_key = KEYPAD_P;
                break;
            case 7:
                act_key = KEYPAD_S;
                break;
        }

        last_key = act_key;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }

    data->key = last_key;
}

#if (ENCODER_INPUT > 0)
/*Initialize your keypad*/
static void encoder_init(void)
{
    encoder.resetEncoder();
}

/*Call this function in an interrupt to process encoder events (turn, press)*/
static void encoder_handler(void)
{
    if (btl_upgrade.bootloader_upgrade_lock(1)) {
        if (encoder.getDevStatus()) {
            encoder_diff = encoder.getIncEncoderValue();
            if (encoder_diff)
                M5.Speaker.tone(3300, 15);
            if (encoder.getButtonStatus())
                encoder_state = LV_INDEV_STATE_REL;
            else
                encoder_state = LV_INDEV_STATE_PR;
        }        
        btl_upgrade.bootloader_upgrade_unlock();
    }
}

/*Will be called by the library to read the encoder*/
static void encoder_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    if (!encoder_test_flag) {
        encoder_handler();
        data->enc_diff = encoder_diff;
        data->state = encoder_state;
    }
    else {
        data->enc_diff = 0;
        data->state = LV_INDEV_STATE_REL;        
    }
}
#endif

static void lv_tick_task(void *arg)
{
    (void)arg;

    lv_tick_inc(LV_TICK_PERIOD_MS);
}

void lvgl_init(void)
{
    lv_init();

    lv_disp_draw_buf_init(&draw_buf, buf1, buf2, LCD_WIDTH * 20);

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = LCD_WIDTH;
    disp_drv.ver_res = LCD_HEIGHT;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    if (M5.getBoard() == m5::board_t::board_M5StackCore2) {
        /*Initialize the (dummy) input device driver*/
        static lv_indev_drv_t indev_drv;
        lv_indev_drv_init(&indev_drv);
        indev_drv.type = LV_INDEV_TYPE_POINTER;
        indev_drv.read_cb = my_touchpad_read;
        lv_indev_drv_register(&indev_drv);

        /*Initialize the (dummy) input device driver*/
        static lv_indev_drv_t indev_drv_btn;
        lv_indev_drv_init(&indev_drv_btn);
        indev_drv_btn.type = LV_INDEV_TYPE_BUTTON;
        indev_drv_btn.read_cb = button_read;
        lv_indev_t *button_indev = lv_indev_drv_register(&indev_drv_btn);

        /*Assign buttons to points on the screen*/
        static const lv_point_t btn_points[3] = {
            {0, 198},   /*Button 0 -> x:10; y:10*/
            {0, 198},  /*Button 1 -> x:40; y:100*/
            {0, 198},  /*Button 1 -> x:40; y:100*/
        };
        lv_indev_set_button_points(button_indev, btn_points);         

        /*Register a keypad input device*/
        static lv_indev_drv_t indev_drv_keypad;
        lv_indev_drv_init(&indev_drv_keypad);
        indev_drv_keypad.type = LV_INDEV_TYPE_KEYPAD;
        indev_drv_keypad.read_cb = keypad_read;
        indev_keypad = lv_indev_drv_register(&indev_drv_keypad);        
    }
    else if (M5.getBoard() == m5::board_t::board_M5Stack) {
        /*Initialize the (dummy) input device driver*/
        static lv_indev_drv_t indev_drv_btn;
        lv_indev_drv_init(&indev_drv_btn);
        indev_drv_btn.type = LV_INDEV_TYPE_BUTTON;
        indev_drv_btn.read_cb = button_read;
        lv_indev_t *button_indev = lv_indev_drv_register(&indev_drv_btn);

        /*Assign buttons to points on the screen*/
        static const lv_point_t btn_points[3] = {
            {0, 198},   /*Button 0 -> x:10; y:10*/
            {0, 198},  /*Button 1 -> x:40; y:100*/
            {0, 198},  /*Button 1 -> x:40; y:100*/
        };
        lv_indev_set_button_points(button_indev, btn_points); 

        /*Register a keypad input device*/
        static lv_indev_drv_t indev_drv_keypad;
        lv_indev_drv_init(&indev_drv_keypad);
        indev_drv_keypad.type = LV_INDEV_TYPE_KEYPAD;
        indev_drv_keypad.read_cb = keypad_read;
        indev_keypad = lv_indev_drv_register(&indev_drv_keypad);                 
    }
#if (ENCODER_INPUT > 0)    
    if (encoder.getDevStatus()) {
        encoder_init();

        /*Register a encoder input device*/
        static lv_indev_drv_t indev_drv_encoder;
        lv_indev_drv_init(&indev_drv_encoder);
        indev_drv_encoder.type = LV_INDEV_TYPE_ENCODER;
        indev_drv_encoder.read_cb = encoder_read;
        indev_encoder = lv_indev_drv_register(&indev_drv_encoder);        
    }
#endif

    /* Create and start a periodic timer interrupt to call lv_tick_inc */
    xGuiSemaphore = xSemaphoreCreateMutex();
    const esp_timer_create_args_t periodic_timer_args = {
        .callback = &lv_tick_task, .name = "periodic_gui"};
    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(
        esp_timer_start_periodic(periodic_timer, LV_TICK_PERIOD_MS * 1000));

    xTaskCreate(example_lvgl_port_task, "LVGL", EXAMPLE_LVGL_TASK_STACK_SIZE, NULL, EXAMPLE_LVGL_TASK_PRIORITY, 
    &task_lvgl_handle); 
}

// Call back function
// void screen_get_value_timer_cb(lv_timer_t *t)
void screen_standby_timer_cb(lv_timer_t *t)
{
    lv_label_set_text_fmt(guider_ui.screen_standby_label_13, "%.3f", pps.getReadbackVoltage());
    lv_label_set_text_fmt(guider_ui.screen_standby_label_14, "%.3f", pps.getReadbackCurrent());

    uint8_t mode = pps.getMode();
    uint8_t output = pps.getPowerEnable();
    float vin = pps.getVIN();
    float temp = pps.getTemperature();

    if (mode <= 1) {
        lv_obj_clear_flag(guider_ui.screen_standby_img_cv, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.screen_standby_img_cc, LV_OBJ_FLAG_HIDDEN);
    }
    else {
        lv_obj_clear_flag(guider_ui.screen_standby_img_cc, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.screen_standby_img_cv, LV_OBJ_FLAG_HIDDEN);
    }

    if (output == 1) {
        lv_obj_clear_flag(guider_ui.screen_standby_img_status_on, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.screen_standby_img_status_off, LV_OBJ_FLAG_HIDDEN);
    }
    else if (output == 0){
        lv_obj_clear_flag(guider_ui.screen_standby_img_status_off, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.screen_standby_img_status_on, LV_OBJ_FLAG_HIDDEN); 
    }

    lv_label_set_text_fmt(guider_ui.screen_standby_label_15, "%.1fV", vin);
    lv_label_set_text_fmt(guider_ui.screen_standby_label_16, "%.0f", temp);
}

void screen_running_timer_cb(lv_timer_t *t)
{
    lv_label_set_text_fmt(guider_ui.screen_running_label_13, "%.3f", pps.getReadbackVoltage());
    lv_label_set_text_fmt(guider_ui.screen_running_label_14, "%.3f", pps.getReadbackCurrent());

    uint8_t mode = pps.getMode();
    uint8_t output = pps.getPowerEnable();
    float vin = pps.getVIN();
    float temp = pps.getTemperature();

    if (mode <= 1) {
        lv_obj_clear_flag(guider_ui.screen_running_img_cv, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.screen_running_img_cc, LV_OBJ_FLAG_HIDDEN);
    }
    else {
        lv_obj_clear_flag(guider_ui.screen_running_img_cc, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.screen_running_img_cv, LV_OBJ_FLAG_HIDDEN);
    }

    if (output == 1) {
        if (flash_fast_flag) {
            lv_obj_clear_flag(guider_ui.screen_running_img_status_on, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.screen_running_img_status_off, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.screen_running_img_status_none, LV_OBJ_FLAG_HIDDEN);
        }
        else {
            lv_obj_clear_flag(guider_ui.screen_running_img_status_none, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.screen_running_img_status_on, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.screen_running_img_status_off, LV_OBJ_FLAG_HIDDEN);            
        }
    }
    else if (output == 0){
        if (flash_slow_flag) {
            lv_obj_clear_flag(guider_ui.screen_running_img_status_off, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.screen_running_img_status_on, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.screen_running_img_status_none, LV_OBJ_FLAG_HIDDEN);
        }
        else {
            lv_obj_clear_flag(guider_ui.screen_running_img_status_none, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.screen_running_img_status_on, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.screen_running_img_status_off, LV_OBJ_FLAG_HIDDEN);            
        }
    }

    lv_label_set_text_fmt(guider_ui.screen_running_label_15, "%.1fV", vin);
    lv_label_set_text_fmt(guider_ui.screen_running_label_16, "%.0f", temp);    
}

void flash_timer_cb(lv_timer_t *t)
{
    flash_counter++;

    if (flash_counter % 50 == 0) {
        if (flash_slow_flag) {
            flash_slow_flag = 0;
        }
        else {
            flash_slow_flag = 1;
        }
    }   

    if (flash_counter % 10 == 0) {
        if (flash_fast_flag) {
            flash_fast_flag = 0;
        }
        else {
            flash_fast_flag = 1;
        }
    }   
}