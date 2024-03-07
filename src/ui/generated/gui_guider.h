/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

extern lv_group_t * group_running;
extern lv_indev_t * indev_keypad;

typedef struct
{
  
	lv_obj_t *screen_standby;
	bool screen_standby_del;
	lv_obj_t *screen_standby_img_bk;
	lv_obj_t *screen_standby_label_v_0;
	lv_obj_t *screen_standby_label_2;
	lv_obj_t *screen_standby_label_v_1;
	lv_obj_t *screen_standby_label_v_2;
	lv_obj_t *screen_standby_label_v_3;
	lv_obj_t *screen_standby_label_v_4;
	lv_obj_t *screen_standby_label_i_4;
	lv_obj_t *screen_standby_label_i_3;
	lv_obj_t *screen_standby_label_i_2;
	lv_obj_t *screen_standby_label_i_1;
	lv_obj_t *screen_standby_label_i_0;
	lv_obj_t *screen_standby_label_12;
	lv_obj_t *screen_standby_img_v_0_0;
	lv_obj_t *screen_standby_img_v_0_1;
	lv_obj_t *screen_standby_img_i_0_0;
	lv_obj_t *screen_standby_img_v_1_0;
	lv_obj_t *screen_standby_img_v_1_1;
	lv_obj_t *screen_standby_img_v_4_0;
	lv_obj_t *screen_standby_img_v_3_0;
	lv_obj_t *screen_standby_img_v_2_0;
	lv_obj_t *screen_standby_img_i_0_1;
	lv_obj_t *screen_standby_cont_1;
	lv_obj_t *screen_standby_cont_2;
	lv_obj_t *screen_standby_label_13;
	lv_obj_t *screen_standby_label_14;
	lv_obj_t *screen_standby_img_v_2_1;
	lv_obj_t *screen_standby_img_v_3_1;
	lv_obj_t *screen_standby_img_v_4_1;
	lv_obj_t *screen_standby_img_i_4_1;
	lv_obj_t *screen_standby_img_i_4_0;
	lv_obj_t *screen_standby_img_i_3_0;
	lv_obj_t *screen_standby_img_i_1_0;
	lv_obj_t *screen_standby_img_i_3_1;
	lv_obj_t *screen_standby_img_i_1_1;
	lv_obj_t *screen_standby_img_i_2_1;
	lv_obj_t *screen_standby_img_i_2_0;
	lv_obj_t *screen_standby_img_output_diabled;
	lv_obj_t *screen_standby_img_cc;
	lv_obj_t *screen_standby_img_output_enable;
	lv_obj_t *screen_standby_img_cv;
	lv_obj_t *screen_standby_btn_1;
	lv_obj_t *screen_standby_btn_1_label;
	lv_obj_t *screen_standby_btn_2;
	lv_obj_t *screen_standby_btn_2_label;
	lv_obj_t *screen_standby_img_status_off;
	lv_obj_t *screen_standby_img_status_on;
	lv_obj_t *screen_standby_label_15;
	lv_obj_t *screen_standby_label_16;	
	lv_obj_t *screen_running;
	bool screen_running_del;
	lv_obj_t *screen_running_img_bk;
	lv_obj_t *screen_running_label_v_0;
	lv_obj_t *screen_running_label_2;
	lv_obj_t *screen_running_label_v_1;
	lv_obj_t *screen_running_label_v_2;
	lv_obj_t *screen_running_label_v_3;
	lv_obj_t *screen_running_label_v_4;
	lv_obj_t *screen_running_label_i_4;
	lv_obj_t *screen_running_label_i_3;
	lv_obj_t *screen_running_label_i_2;
	lv_obj_t *screen_running_label_i_1;
	lv_obj_t *screen_running_label_i_0;
	lv_obj_t *screen_running_label_12;
	lv_obj_t *screen_running_img_v_0_0;
	lv_obj_t *screen_running_img_v_0_1;
	lv_obj_t *screen_running_img_i_0_0;
	lv_obj_t *screen_running_img_v_1_0;
	lv_obj_t *screen_running_img_v_1_1;
	lv_obj_t *screen_running_img_v_4_0;
	lv_obj_t *screen_running_img_v_3_0;
	lv_obj_t *screen_running_img_v_2_0;
	lv_obj_t *screen_running_img_i_0_1;
	lv_obj_t *screen_running_cont_1;
	lv_obj_t *screen_running_cont_2;
	lv_obj_t *screen_running_label_13;
	lv_obj_t *screen_running_label_14;
	lv_obj_t *screen_running_img_v_2_1;
	lv_obj_t *screen_running_img_v_3_1;
	lv_obj_t *screen_running_img_v_4_1;
	lv_obj_t *screen_running_img_i_4_1;
	lv_obj_t *screen_running_img_i_4_0;
	lv_obj_t *screen_running_img_i_3_0;
	lv_obj_t *screen_running_img_i_1_0;
	lv_obj_t *screen_running_img_i_3_1;
	lv_obj_t *screen_running_img_i_1_1;
	lv_obj_t *screen_running_img_i_2_1;
	lv_obj_t *screen_running_img_i_2_0;
	lv_obj_t *screen_running_img_output_diabled;
	lv_obj_t *screen_running_img_cc;
	lv_obj_t *screen_running_img_output_enable;
	lv_obj_t *screen_running_img_cv;
	lv_obj_t *screen_running_btn_1;
	lv_obj_t *screen_running_btn_1_label;
	lv_obj_t *screen_running_img_1;
	lv_obj_t *screen_running_img_status_on;
	lv_obj_t *screen_running_img_status_off;
	lv_obj_t *screen_running_img_5;
	lv_obj_t *screen_running_label_15;
	lv_obj_t *screen_running_label_16;	
	lv_obj_t *screen_running_btn_a_short;
	lv_obj_t *screen_running_btn_a_short_label;
	lv_obj_t *screen_running_btn_b_short;
	lv_obj_t *screen_running_btn_b_short_label;
	lv_obj_t *screen_running_btn_c_short;
	lv_obj_t *screen_running_btn_c_short_label;
	lv_obj_t *screen_running_btn_c_long;
	lv_obj_t *screen_running_btn_c_long_label;
	lv_obj_t *screen_running_btn_b_long;
	lv_obj_t *screen_running_btn_b_long_label;
	lv_obj_t *screen_running_btn_a_long;
	lv_obj_t *screen_running_btn_a_long_label;
	lv_obj_t *screen_running_img_loud;
	lv_obj_t *screen_running_img_mute;	
	lv_obj_t *screen_running_img_status_none;	
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_move_animation(void * var, int32_t duration, int32_t delay, int32_t x_end, int32_t y_end, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_scale_animation(void * var, int32_t duration, int32_t delay, int32_t width, int32_t height, lv_anim_path_cb_t path_cb,
                        uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                        lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_zoom_animation(void * var, int32_t duration, int32_t delay, int32_t zoom, lv_anim_path_cb_t path_cb,
                           uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                           lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_rotate_animation(void * var, int32_t duration, int32_t delay, lv_coord_t x, lv_coord_t y, int32_t rotate,
                   lv_anim_path_cb_t path_cb, uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time,
                   uint32_t playback_delay, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;

void setup_scr_screen_standby(lv_ui *ui);
void setup_scr_screen_running(lv_ui *ui);
LV_IMG_DECLARE(_bk_alpha_320x240);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_output_disabled_alpha_52x52);
LV_IMG_DECLARE(_cc_alpha_52x42);
LV_IMG_DECLARE(_output_enable_alpha_52x52);
LV_IMG_DECLARE(_cv_alpha_52x42);
LV_IMG_DECLARE(_output_off_alpha_94x26);
LV_IMG_DECLARE(_output_on_alpha_94x26);
LV_IMG_DECLARE(_bk0_alpha_320x240);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_numberSelected_alpha_18x5);
LV_IMG_DECLARE(_output_disabled_alpha_52x52);
LV_IMG_DECLARE(_cc_alpha_52x42);
LV_IMG_DECLARE(_output_enable_alpha_52x52);
LV_IMG_DECLARE(_cv_alpha_52x42);
LV_IMG_DECLARE(_menu_status_0_alpha_320x48);
LV_IMG_DECLARE(_output_on_alpha_94x26);
LV_IMG_DECLARE(_output_off_alpha_94x26);
LV_IMG_DECLARE(_menu_status_5_alpha_320x48);
LV_IMG_DECLARE(_loud_alpha_72x20);
LV_IMG_DECLARE(_mute_alpha_72x18);
LV_IMG_DECLARE(_output_none_alpha_94x26);

LV_FONT_DECLARE(lv_font_Barlow_Light_36)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_Barlow_Light_22)
LV_FONT_DECLARE(lv_font_Barlow_Light_32)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_Barlow_Light_16)


#ifdef __cplusplus
}
#endif
#endif
