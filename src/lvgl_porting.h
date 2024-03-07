#ifndef _LVGL_PORTING_H_
#define _LVGL_PORTING_H_

#include "main.h"

#include <lvgl.h>

#include "./ui/generated/gui_guider.h"
#include "./ui/generated/custom.h"
#include "./ui/generated/events_init.h"

#define ENCODER_INPUT 0

#define KEYPAD_P 80
#define KEYPAD_S 83

void lvgl_init(void);
bool example_lvgl_lock(int timeout_ms);
void example_lvgl_unlock(void);

// Call back function
void screen_standby_timer_cb(lv_timer_t *t);
void screen_running_timer_cb(lv_timer_t *t);
void flash_timer_cb(lv_timer_t *t);

extern TaskHandle_t task_lvgl_handle;

enum {PAGE_STANDBY = 0, PAGE_RUNNING};
extern uint8_t page_number;

#if (ENCODER_INPUT > 0)
extern uint8_t encoder_test_flag;
#endif

#endif

