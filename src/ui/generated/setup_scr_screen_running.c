/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen_running(lv_ui *ui)
{
	//Write codes screen_running
	ui->screen_running = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_running, 320, 240);
	lv_obj_set_scrollbar_mode(ui->screen_running, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_running, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_running, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_bk
	ui->screen_running_img_bk = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_bk, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_bk, &_bk0_alpha_320x240);
	lv_img_set_pivot(ui->screen_running_img_bk, 50,50);
	lv_img_set_angle(ui->screen_running_img_bk, 0);
	lv_obj_set_pos(ui->screen_running_img_bk, 0, 0);
	lv_obj_set_size(ui->screen_running_img_bk, 320, 240);

	//Write style for screen_running_img_bk, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_bk, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_label_v_0
	ui->screen_running_label_v_0 = lv_label_create(ui->screen_running);
	lv_label_set_text(ui->screen_running_label_v_0, "0");
	lv_label_set_long_mode(ui->screen_running_label_v_0, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_running_label_v_0, 41, 66);
	lv_obj_set_size(ui->screen_running_label_v_0, 18, 36);

	//Write style for screen_running_label_v_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_running_label_v_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_label_v_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_label_v_0, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_label_v_0, &lv_font_Barlow_Light_36, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_label_v_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_running_label_v_0, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_running_label_v_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_label_v_0, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_running_label_v_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_running_label_v_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_running_label_v_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_running_label_v_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_running_label_v_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_label_v_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_label_2
	ui->screen_running_label_2 = lv_label_create(ui->screen_running);
	lv_label_set_text(ui->screen_running_label_2, ".");
	lv_label_set_long_mode(ui->screen_running_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_running_label_2, 82, 79);
	lv_obj_set_size(ui->screen_running_label_2, 9, 36);

	//Write style for screen_running_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_running_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_label_2, &lv_font_Barlow_Light_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_running_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_running_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_running_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_running_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_running_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_running_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_running_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_label_v_1
	ui->screen_running_label_v_1 = lv_label_create(ui->screen_running);
	lv_label_set_text(ui->screen_running_label_v_1, "0");
	lv_label_set_long_mode(ui->screen_running_label_v_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_running_label_v_1, 59, 66);
	lv_obj_set_size(ui->screen_running_label_v_1, 18, 36);

	//Write style for screen_running_label_v_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_running_label_v_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_label_v_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_label_v_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_label_v_1, &lv_font_Barlow_Light_36, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_label_v_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_running_label_v_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_running_label_v_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_label_v_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_running_label_v_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_running_label_v_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_running_label_v_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_running_label_v_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_running_label_v_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_label_v_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_label_v_2
	ui->screen_running_label_v_2 = lv_label_create(ui->screen_running);
	lv_label_set_text(ui->screen_running_label_v_2, "0");
	lv_label_set_long_mode(ui->screen_running_label_v_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_running_label_v_2, 95, 66);
	lv_obj_set_size(ui->screen_running_label_v_2, 18, 36);

	//Write style for screen_running_label_v_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_running_label_v_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_label_v_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_label_v_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_label_v_2, &lv_font_Barlow_Light_36, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_label_v_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_running_label_v_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_running_label_v_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_label_v_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_running_label_v_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_running_label_v_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_running_label_v_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_running_label_v_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_running_label_v_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_label_v_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_label_v_3
	ui->screen_running_label_v_3 = lv_label_create(ui->screen_running);
	lv_label_set_text(ui->screen_running_label_v_3, "0");
	lv_label_set_long_mode(ui->screen_running_label_v_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_running_label_v_3, 113, 66);
	lv_obj_set_size(ui->screen_running_label_v_3, 18, 36);

	//Write style for screen_running_label_v_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_running_label_v_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_label_v_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_label_v_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_label_v_3, &lv_font_Barlow_Light_36, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_label_v_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_running_label_v_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_running_label_v_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_label_v_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_running_label_v_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_running_label_v_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_running_label_v_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_running_label_v_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_running_label_v_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_label_v_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_label_v_4
	ui->screen_running_label_v_4 = lv_label_create(ui->screen_running);
	lv_label_set_text(ui->screen_running_label_v_4, "0");
	lv_label_set_long_mode(ui->screen_running_label_v_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_running_label_v_4, 131, 66);
	lv_obj_set_size(ui->screen_running_label_v_4, 18, 36);

	//Write style for screen_running_label_v_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_running_label_v_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_label_v_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_label_v_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_label_v_4, &lv_font_Barlow_Light_36, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_label_v_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_running_label_v_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_running_label_v_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_label_v_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_running_label_v_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_running_label_v_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_running_label_v_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_running_label_v_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_running_label_v_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_label_v_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_label_i_4
	ui->screen_running_label_i_4 = lv_label_create(ui->screen_running);
	lv_label_set_text(ui->screen_running_label_i_4, "0");
	lv_label_set_long_mode(ui->screen_running_label_i_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_running_label_i_4, 131, 130);
	lv_obj_set_size(ui->screen_running_label_i_4, 18, 36);

	//Write style for screen_running_label_i_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_running_label_i_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_label_i_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_label_i_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_label_i_4, &lv_font_Barlow_Light_36, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_label_i_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_running_label_i_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_running_label_i_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_label_i_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_running_label_i_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_running_label_i_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_running_label_i_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_running_label_i_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_running_label_i_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_label_i_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_label_i_3
	ui->screen_running_label_i_3 = lv_label_create(ui->screen_running);
	lv_label_set_text(ui->screen_running_label_i_3, "0");
	lv_label_set_long_mode(ui->screen_running_label_i_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_running_label_i_3, 113, 130);
	lv_obj_set_size(ui->screen_running_label_i_3, 18, 36);

	//Write style for screen_running_label_i_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_running_label_i_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_label_i_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_label_i_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_label_i_3, &lv_font_Barlow_Light_36, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_label_i_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_running_label_i_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_running_label_i_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_label_i_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_running_label_i_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_running_label_i_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_running_label_i_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_running_label_i_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_running_label_i_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_label_i_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_label_i_2
	ui->screen_running_label_i_2 = lv_label_create(ui->screen_running);
	lv_label_set_text(ui->screen_running_label_i_2, "0");
	lv_label_set_long_mode(ui->screen_running_label_i_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_running_label_i_2, 95, 130);
	lv_obj_set_size(ui->screen_running_label_i_2, 18, 36);

	//Write style for screen_running_label_i_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_running_label_i_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_label_i_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_label_i_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_label_i_2, &lv_font_Barlow_Light_36, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_label_i_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_running_label_i_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_running_label_i_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_label_i_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_running_label_i_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_running_label_i_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_running_label_i_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_running_label_i_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_running_label_i_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_label_i_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_label_i_1
	ui->screen_running_label_i_1 = lv_label_create(ui->screen_running);
	lv_label_set_text(ui->screen_running_label_i_1, "0");
	lv_label_set_long_mode(ui->screen_running_label_i_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_running_label_i_1, 59, 130);
	lv_obj_set_size(ui->screen_running_label_i_1, 18, 36);

	//Write style for screen_running_label_i_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_running_label_i_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_label_i_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_label_i_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_label_i_1, &lv_font_Barlow_Light_36, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_label_i_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_running_label_i_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_running_label_i_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_label_i_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_running_label_i_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_running_label_i_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_running_label_i_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_running_label_i_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_running_label_i_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_label_i_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_label_i_0
	ui->screen_running_label_i_0 = lv_label_create(ui->screen_running);
	lv_label_set_text(ui->screen_running_label_i_0, "0");
	lv_label_set_long_mode(ui->screen_running_label_i_0, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_running_label_i_0, 41, 130);
	lv_obj_set_size(ui->screen_running_label_i_0, 18, 36);

	//Write style for screen_running_label_i_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_running_label_i_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_label_i_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_label_i_0, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_label_i_0, &lv_font_Barlow_Light_36, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_label_i_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_running_label_i_0, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_running_label_i_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_label_i_0, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_running_label_i_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_running_label_i_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_running_label_i_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_running_label_i_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_running_label_i_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_label_i_0, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_label_12
	ui->screen_running_label_12 = lv_label_create(ui->screen_running);
	lv_label_set_text(ui->screen_running_label_12, ".");
	lv_label_set_long_mode(ui->screen_running_label_12, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_running_label_12, 82, 143);
	lv_obj_set_size(ui->screen_running_label_12, 9, 36);

	//Write style for screen_running_label_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_running_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_label_12, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_label_12, &lv_font_Barlow_Light_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_running_label_12, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_running_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_label_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_running_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_running_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_running_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_running_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_running_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_v_0_0
	ui->screen_running_img_v_0_0 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_v_0_0, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_v_0_0, &_numberSelected_alpha_18x5);
	lv_img_set_pivot(ui->screen_running_img_v_0_0, 50,50);
	lv_img_set_angle(ui->screen_running_img_v_0_0, 0);
	lv_obj_set_pos(ui->screen_running_img_v_0_0, 41, 56);
	lv_obj_set_size(ui->screen_running_img_v_0_0, 18, 5);

	//Write style for screen_running_img_v_0_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_v_0_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_v_0_1
	ui->screen_running_img_v_0_1 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_v_0_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_v_0_1, &_numberSelected_alpha_18x5);
	lv_img_set_pivot(ui->screen_running_img_v_0_1, 50,50);
	lv_img_set_angle(ui->screen_running_img_v_0_1, 0);
	lv_obj_set_pos(ui->screen_running_img_v_0_1, 41, 108);
	lv_obj_set_size(ui->screen_running_img_v_0_1, 18, 5);

	//Write style for screen_running_img_v_0_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_v_0_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_i_0_0
	ui->screen_running_img_i_0_0 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_i_0_0, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_i_0_0, &_numberSelected_alpha_18x5);
	lv_img_set_pivot(ui->screen_running_img_i_0_0, 50,50);
	lv_img_set_angle(ui->screen_running_img_i_0_0, 0);
	lv_obj_set_pos(ui->screen_running_img_i_0_0, 41, 120);
	lv_obj_set_size(ui->screen_running_img_i_0_0, 18, 5);
	lv_obj_add_flag(ui->screen_running_img_i_0_0, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_i_0_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_i_0_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_v_1_0
	ui->screen_running_img_v_1_0 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_v_1_0, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_v_1_0, &_numberSelected_alpha_18x5);
	lv_img_set_pivot(ui->screen_running_img_v_1_0, 50,50);
	lv_img_set_angle(ui->screen_running_img_v_1_0, 0);
	lv_obj_set_pos(ui->screen_running_img_v_1_0, 59, 56);
	lv_obj_set_size(ui->screen_running_img_v_1_0, 18, 5);
	lv_obj_add_flag(ui->screen_running_img_v_1_0, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_v_1_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_v_1_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_v_1_1
	ui->screen_running_img_v_1_1 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_v_1_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_v_1_1, &_numberSelected_alpha_18x5);
	lv_img_set_pivot(ui->screen_running_img_v_1_1, 50,50);
	lv_img_set_angle(ui->screen_running_img_v_1_1, 0);
	lv_obj_set_pos(ui->screen_running_img_v_1_1, 59, 108);
	lv_obj_set_size(ui->screen_running_img_v_1_1, 18, 5);
	lv_obj_add_flag(ui->screen_running_img_v_1_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_v_1_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_v_1_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_v_4_0
	ui->screen_running_img_v_4_0 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_v_4_0, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_v_4_0, &_numberSelected_alpha_18x5);
	lv_img_set_pivot(ui->screen_running_img_v_4_0, 50,50);
	lv_img_set_angle(ui->screen_running_img_v_4_0, 0);
	lv_obj_set_pos(ui->screen_running_img_v_4_0, 131, 56);
	lv_obj_set_size(ui->screen_running_img_v_4_0, 18, 5);
	lv_obj_add_flag(ui->screen_running_img_v_4_0, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_v_4_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_v_4_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_v_3_0
	ui->screen_running_img_v_3_0 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_v_3_0, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_v_3_0, &_numberSelected_alpha_18x5);
	lv_img_set_pivot(ui->screen_running_img_v_3_0, 50,50);
	lv_img_set_angle(ui->screen_running_img_v_3_0, 0);
	lv_obj_set_pos(ui->screen_running_img_v_3_0, 113, 56);
	lv_obj_set_size(ui->screen_running_img_v_3_0, 18, 5);
	lv_obj_add_flag(ui->screen_running_img_v_3_0, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_v_3_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_v_3_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_v_2_0
	ui->screen_running_img_v_2_0 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_v_2_0, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_v_2_0, &_numberSelected_alpha_18x5);
	lv_img_set_pivot(ui->screen_running_img_v_2_0, 50,50);
	lv_img_set_angle(ui->screen_running_img_v_2_0, 0);
	lv_obj_set_pos(ui->screen_running_img_v_2_0, 95, 56);
	lv_obj_set_size(ui->screen_running_img_v_2_0, 18, 5);
	lv_obj_add_flag(ui->screen_running_img_v_2_0, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_v_2_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_v_2_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_i_0_1
	ui->screen_running_img_i_0_1 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_i_0_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_i_0_1, &_numberSelected_alpha_18x5);
	lv_img_set_pivot(ui->screen_running_img_i_0_1, 50,50);
	lv_img_set_angle(ui->screen_running_img_i_0_1, 0);
	lv_obj_set_pos(ui->screen_running_img_i_0_1, 41, 172);
	lv_obj_set_size(ui->screen_running_img_i_0_1, 18, 5);
	lv_obj_add_flag(ui->screen_running_img_i_0_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_i_0_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_i_0_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_cont_1
	ui->screen_running_cont_1 = lv_obj_create(ui->screen_running);
	lv_obj_set_pos(ui->screen_running_cont_1, 36, 55);
	lv_obj_set_size(ui->screen_running_cont_1, 110, 56);
	lv_obj_set_scrollbar_mode(ui->screen_running_cont_1, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_running_cont_1, LV_OBJ_FLAG_CLICKABLE);

	//Write style for screen_running_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_running_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_running_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_running_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_running_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_running_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_running_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_running_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_running_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_running_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_cont_2
	ui->screen_running_cont_2 = lv_obj_create(ui->screen_running);
	lv_obj_set_pos(ui->screen_running_cont_2, 36, 122);
	lv_obj_set_size(ui->screen_running_cont_2, 110, 56);
	lv_obj_set_scrollbar_mode(ui->screen_running_cont_2, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_flag(ui->screen_running_cont_2, LV_OBJ_FLAG_CLICKABLE);

	//Write style for screen_running_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_running_cont_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_running_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_running_cont_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_running_cont_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_running_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_running_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_running_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_running_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_running_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_label_13
	ui->screen_running_label_13 = lv_label_create(ui->screen_running);
	lv_label_set_text(ui->screen_running_label_13, "30.000");
	lv_label_set_long_mode(ui->screen_running_label_13, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_running_label_13, 203, 69);
	lv_obj_set_size(ui->screen_running_label_13, 112, 36);

	//Write style for screen_running_label_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_running_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_label_13, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_label_13, &lv_font_Barlow_Light_32, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_label_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_running_label_13, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_running_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_label_13, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_running_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_running_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_running_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_running_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_running_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_label_14
	ui->screen_running_label_14 = lv_label_create(ui->screen_running);
	lv_label_set_text(ui->screen_running_label_14, "5.000");
	lv_label_set_long_mode(ui->screen_running_label_14, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_running_label_14, 203, 133);
	lv_obj_set_size(ui->screen_running_label_14, 112, 36);

	//Write style for screen_running_label_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_running_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_label_14, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_label_14, &lv_font_Barlow_Light_32, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_label_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_running_label_14, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_running_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_label_14, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_running_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_running_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_running_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_running_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_running_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_v_2_1
	ui->screen_running_img_v_2_1 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_v_2_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_v_2_1, &_numberSelected_alpha_18x5);
	lv_img_set_pivot(ui->screen_running_img_v_2_1, 50,50);
	lv_img_set_angle(ui->screen_running_img_v_2_1, 0);
	lv_obj_set_pos(ui->screen_running_img_v_2_1, 95, 108);
	lv_obj_set_size(ui->screen_running_img_v_2_1, 18, 5);
	lv_obj_add_flag(ui->screen_running_img_v_2_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_v_2_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_v_2_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_v_3_1
	ui->screen_running_img_v_3_1 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_v_3_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_v_3_1, &_numberSelected_alpha_18x5);
	lv_img_set_pivot(ui->screen_running_img_v_3_1, 50,50);
	lv_img_set_angle(ui->screen_running_img_v_3_1, 0);
	lv_obj_set_pos(ui->screen_running_img_v_3_1, 113, 108);
	lv_obj_set_size(ui->screen_running_img_v_3_1, 18, 5);
	lv_obj_add_flag(ui->screen_running_img_v_3_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_v_3_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_v_3_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_v_4_1
	ui->screen_running_img_v_4_1 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_v_4_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_v_4_1, &_numberSelected_alpha_18x5);
	lv_img_set_pivot(ui->screen_running_img_v_4_1, 50,50);
	lv_img_set_angle(ui->screen_running_img_v_4_1, 0);
	lv_obj_set_pos(ui->screen_running_img_v_4_1, 131, 108);
	lv_obj_set_size(ui->screen_running_img_v_4_1, 18, 5);
	lv_obj_add_flag(ui->screen_running_img_v_4_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_v_4_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_v_4_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_i_4_1
	ui->screen_running_img_i_4_1 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_i_4_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_i_4_1, &_numberSelected_alpha_18x5);
	lv_img_set_pivot(ui->screen_running_img_i_4_1, 50,50);
	lv_img_set_angle(ui->screen_running_img_i_4_1, 0);
	lv_obj_set_pos(ui->screen_running_img_i_4_1, 131, 172);
	lv_obj_set_size(ui->screen_running_img_i_4_1, 18, 5);
	lv_obj_add_flag(ui->screen_running_img_i_4_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_i_4_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_i_4_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_i_4_0
	ui->screen_running_img_i_4_0 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_i_4_0, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_i_4_0, &_numberSelected_alpha_18x5);
	lv_img_set_pivot(ui->screen_running_img_i_4_0, 50,50);
	lv_img_set_angle(ui->screen_running_img_i_4_0, 0);
	lv_obj_set_pos(ui->screen_running_img_i_4_0, 131, 120);
	lv_obj_set_size(ui->screen_running_img_i_4_0, 18, 5);
	lv_obj_add_flag(ui->screen_running_img_i_4_0, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_i_4_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_i_4_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_i_3_0
	ui->screen_running_img_i_3_0 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_i_3_0, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_i_3_0, &_numberSelected_alpha_18x5);
	lv_img_set_pivot(ui->screen_running_img_i_3_0, 50,50);
	lv_img_set_angle(ui->screen_running_img_i_3_0, 0);
	lv_obj_set_pos(ui->screen_running_img_i_3_0, 113, 120);
	lv_obj_set_size(ui->screen_running_img_i_3_0, 18, 5);
	lv_obj_add_flag(ui->screen_running_img_i_3_0, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_i_3_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_i_3_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_i_1_0
	ui->screen_running_img_i_1_0 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_i_1_0, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_i_1_0, &_numberSelected_alpha_18x5);
	lv_img_set_pivot(ui->screen_running_img_i_1_0, 50,50);
	lv_img_set_angle(ui->screen_running_img_i_1_0, 0);
	lv_obj_set_pos(ui->screen_running_img_i_1_0, 59, 120);
	lv_obj_set_size(ui->screen_running_img_i_1_0, 18, 5);
	lv_obj_add_flag(ui->screen_running_img_i_1_0, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_i_1_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_i_1_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_i_3_1
	ui->screen_running_img_i_3_1 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_i_3_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_i_3_1, &_numberSelected_alpha_18x5);
	lv_img_set_pivot(ui->screen_running_img_i_3_1, 50,50);
	lv_img_set_angle(ui->screen_running_img_i_3_1, 0);
	lv_obj_set_pos(ui->screen_running_img_i_3_1, 113, 172);
	lv_obj_set_size(ui->screen_running_img_i_3_1, 18, 5);
	lv_obj_add_flag(ui->screen_running_img_i_3_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_i_3_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_i_3_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_i_1_1
	ui->screen_running_img_i_1_1 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_i_1_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_i_1_1, &_numberSelected_alpha_18x5);
	lv_img_set_pivot(ui->screen_running_img_i_1_1, 50,50);
	lv_img_set_angle(ui->screen_running_img_i_1_1, 0);
	lv_obj_set_pos(ui->screen_running_img_i_1_1, 59, 172);
	lv_obj_set_size(ui->screen_running_img_i_1_1, 18, 5);
	lv_obj_add_flag(ui->screen_running_img_i_1_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_i_1_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_i_1_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_i_2_1
	ui->screen_running_img_i_2_1 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_i_2_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_i_2_1, &_numberSelected_alpha_18x5);
	lv_img_set_pivot(ui->screen_running_img_i_2_1, 50,50);
	lv_img_set_angle(ui->screen_running_img_i_2_1, 0);
	lv_obj_set_pos(ui->screen_running_img_i_2_1, 95, 172);
	lv_obj_set_size(ui->screen_running_img_i_2_1, 18, 5);
	lv_obj_add_flag(ui->screen_running_img_i_2_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_i_2_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_i_2_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_i_2_0
	ui->screen_running_img_i_2_0 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_i_2_0, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_i_2_0, &_numberSelected_alpha_18x5);
	lv_img_set_pivot(ui->screen_running_img_i_2_0, 50,50);
	lv_img_set_angle(ui->screen_running_img_i_2_0, 0);
	lv_obj_set_pos(ui->screen_running_img_i_2_0, 95, 120);
	lv_obj_set_size(ui->screen_running_img_i_2_0, 18, 5);
	lv_obj_add_flag(ui->screen_running_img_i_2_0, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_i_2_0, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_i_2_0, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_output_diabled
	ui->screen_running_img_output_diabled = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_output_diabled, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_output_diabled, &_output_disabled_alpha_52x52);
	lv_img_set_pivot(ui->screen_running_img_output_diabled, 50,50);
	lv_img_set_angle(ui->screen_running_img_output_diabled, 0);
	lv_obj_set_pos(ui->screen_running_img_output_diabled, 152, 58);
	lv_obj_set_size(ui->screen_running_img_output_diabled, 52, 52);

	//Write style for screen_running_img_output_diabled, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_output_diabled, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_cc
	ui->screen_running_img_cc = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_cc, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_cc, &_cc_alpha_52x42);
	lv_img_set_pivot(ui->screen_running_img_cc, 50,50);
	lv_img_set_angle(ui->screen_running_img_cc, 0);
	lv_obj_set_pos(ui->screen_running_img_cc, 152, 136);
	lv_obj_set_size(ui->screen_running_img_cc, 52, 42);

	//Write style for screen_running_img_cc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_cc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_output_enable
	ui->screen_running_img_output_enable = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_output_enable, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_output_enable, &_output_enable_alpha_52x52);
	lv_img_set_pivot(ui->screen_running_img_output_enable, 50,50);
	lv_img_set_angle(ui->screen_running_img_output_enable, 0);
	lv_obj_set_pos(ui->screen_running_img_output_enable, 152, 58);
	lv_obj_set_size(ui->screen_running_img_output_enable, 52, 52);
	lv_obj_add_flag(ui->screen_running_img_output_enable, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_output_enable, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_output_enable, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_cv
	ui->screen_running_img_cv = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_cv, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_cv, &_cv_alpha_52x42);
	lv_img_set_pivot(ui->screen_running_img_cv, 50,50);
	lv_img_set_angle(ui->screen_running_img_cv, 0);
	lv_obj_set_pos(ui->screen_running_img_cv, 152, 136);
	lv_obj_set_size(ui->screen_running_img_cv, 52, 42);
	lv_obj_add_flag(ui->screen_running_img_cv, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_cv, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_cv, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_btn_1
	ui->screen_running_btn_1 = lv_btn_create(ui->screen_running);
	ui->screen_running_btn_1_label = lv_label_create(ui->screen_running_btn_1);
	lv_label_set_text(ui->screen_running_btn_1_label, "");
	lv_label_set_long_mode(ui->screen_running_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_running_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_running_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_running_btn_1, 161, 66);
	lv_obj_set_size(ui->screen_running_btn_1, 40, 36);

	//Write style for screen_running_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_running_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_running_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_1
	ui->screen_running_img_1 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_1, &_menu_status_0_alpha_320x48);
	lv_img_set_pivot(ui->screen_running_img_1, 50,50);
	lv_img_set_angle(ui->screen_running_img_1, 0);
	lv_obj_set_pos(ui->screen_running_img_1, 0, 192);
	lv_obj_set_size(ui->screen_running_img_1, 320, 48);

	//Write style for screen_running_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_status_on
	ui->screen_running_img_status_on = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_status_on, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_status_on, &_output_on_alpha_94x26);
	lv_img_set_pivot(ui->screen_running_img_status_on, 50,50);
	lv_img_set_angle(ui->screen_running_img_status_on, 0);
	lv_obj_set_pos(ui->screen_running_img_status_on, 226, 0);
	lv_obj_set_size(ui->screen_running_img_status_on, 94, 26);
	lv_obj_add_flag(ui->screen_running_img_status_on, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_status_on, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_status_on, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_status_off
	ui->screen_running_img_status_off = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_status_off, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_status_off, &_output_off_alpha_94x26);
	lv_img_set_pivot(ui->screen_running_img_status_off, 50,50);
	lv_img_set_angle(ui->screen_running_img_status_off, 0);
	lv_obj_set_pos(ui->screen_running_img_status_off, 226, 0);
	lv_obj_set_size(ui->screen_running_img_status_off, 94, 26);

	//Write style for screen_running_img_status_off, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_status_off, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_5
	ui->screen_running_img_5 = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_5, &_menu_status_5_alpha_320x48);
	lv_img_set_pivot(ui->screen_running_img_5, 50,50);
	lv_img_set_angle(ui->screen_running_img_5, 0);
	lv_obj_set_pos(ui->screen_running_img_5, 0, 192);
	lv_obj_set_size(ui->screen_running_img_5, 320, 48);
	lv_obj_add_flag(ui->screen_running_img_5, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_label_15
	ui->screen_running_label_15 = lv_label_create(ui->screen_running);
	lv_label_set_text(ui->screen_running_label_15, "12.1V");
	lv_label_set_long_mode(ui->screen_running_label_15, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_running_label_15, 41, 5);
	lv_obj_set_size(ui->screen_running_label_15, 50, 20);

	//Write style for screen_running_label_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_running_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_label_15, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_label_15, &lv_font_Barlow_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_label_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_running_label_15, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_running_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_label_15, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_running_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_running_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_running_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_running_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_running_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_label_16
	ui->screen_running_label_16 = lv_label_create(ui->screen_running);
	lv_label_set_text(ui->screen_running_label_16, "35");
	lv_label_set_long_mode(ui->screen_running_label_16, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_running_label_16, 172, 5);
	lv_obj_set_size(ui->screen_running_label_16, 36, 20);

	//Write style for screen_running_label_16, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_running_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_label_16, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_label_16, &lv_font_Barlow_Light_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_label_16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_running_label_16, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_running_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_label_16, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_running_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_running_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_running_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_running_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_running_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_btn_a_short
	ui->screen_running_btn_a_short = lv_btn_create(ui->screen_running);
	ui->screen_running_btn_a_short_label = lv_label_create(ui->screen_running_btn_a_short);
	lv_label_set_text(ui->screen_running_btn_a_short_label, "");
	lv_label_set_long_mode(ui->screen_running_btn_a_short_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_running_btn_a_short_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_running_btn_a_short, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_running_btn_a_short, 32, 192);
	lv_obj_set_size(ui->screen_running_btn_a_short, 73, 26);

	//Write style for screen_running_btn_a_short, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_running_btn_a_short, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_running_btn_a_short, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_btn_a_short, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_btn_a_short, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_btn_a_short, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_btn_a_short, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_btn_a_short, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_btn_a_short, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_btn_b_short
	ui->screen_running_btn_b_short = lv_btn_create(ui->screen_running);
	ui->screen_running_btn_b_short_label = lv_label_create(ui->screen_running_btn_b_short);
	lv_label_set_text(ui->screen_running_btn_b_short_label, "");
	lv_label_set_long_mode(ui->screen_running_btn_b_short_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_running_btn_b_short_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_running_btn_b_short, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_running_btn_b_short, 124, 192);
	lv_obj_set_size(ui->screen_running_btn_b_short, 73, 26);

	//Write style for screen_running_btn_b_short, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_running_btn_b_short, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_running_btn_b_short, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_btn_b_short, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_btn_b_short, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_btn_b_short, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_btn_b_short, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_btn_b_short, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_btn_b_short, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_btn_c_short
	ui->screen_running_btn_c_short = lv_btn_create(ui->screen_running);
	ui->screen_running_btn_c_short_label = lv_label_create(ui->screen_running_btn_c_short);
	lv_label_set_text(ui->screen_running_btn_c_short_label, "");
	lv_label_set_long_mode(ui->screen_running_btn_c_short_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_running_btn_c_short_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_running_btn_c_short, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_running_btn_c_short, 215, 192);
	lv_obj_set_size(ui->screen_running_btn_c_short, 73, 26);

	//Write style for screen_running_btn_c_short, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_running_btn_c_short, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_running_btn_c_short, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_btn_c_short, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_btn_c_short, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_btn_c_short, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_btn_c_short, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_btn_c_short, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_btn_c_short, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_btn_c_long
	ui->screen_running_btn_c_long = lv_btn_create(ui->screen_running);
	ui->screen_running_btn_c_long_label = lv_label_create(ui->screen_running_btn_c_long);
	lv_label_set_text(ui->screen_running_btn_c_long_label, "");
	lv_label_set_long_mode(ui->screen_running_btn_c_long_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_running_btn_c_long_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_running_btn_c_long, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_running_btn_c_long, 215, 219);
	lv_obj_set_size(ui->screen_running_btn_c_long, 73, 21);

	//Write style for screen_running_btn_c_long, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_running_btn_c_long, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_running_btn_c_long, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_btn_c_long, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_btn_c_long, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_btn_c_long, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_btn_c_long, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_btn_c_long, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_btn_c_long, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_btn_a_long
	ui->screen_running_btn_a_long = lv_btn_create(ui->screen_running);
	ui->screen_running_btn_a_long_label = lv_label_create(ui->screen_running_btn_a_long);
	lv_label_set_text(ui->screen_running_btn_a_long_label, "");
	lv_label_set_long_mode(ui->screen_running_btn_a_long_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_running_btn_a_long_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_running_btn_a_long, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_running_btn_a_long, 32, 219);
	lv_obj_set_size(ui->screen_running_btn_a_long, 73, 21);

	//Write style for screen_running_btn_a_long, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_running_btn_a_long, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_running_btn_a_long, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_btn_a_long, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_btn_a_long, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_btn_a_long, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_btn_a_long, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_btn_a_long, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_btn_a_long, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_loud
	ui->screen_running_img_loud = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_loud, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_loud, &_loud_alpha_72x20);
	lv_img_set_pivot(ui->screen_running_img_loud, 50,50);
	lv_img_set_angle(ui->screen_running_img_loud, 0);
	lv_obj_set_pos(ui->screen_running_img_loud, 124, 220);
	lv_obj_set_size(ui->screen_running_img_loud, 72, 20);
	lv_obj_add_flag(ui->screen_running_img_loud, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_loud, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_loud, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_mute
	ui->screen_running_img_mute = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_mute, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_mute, &_mute_alpha_72x18);
	lv_img_set_pivot(ui->screen_running_img_mute, 50,50);
	lv_img_set_angle(ui->screen_running_img_mute, 0);
	lv_obj_set_pos(ui->screen_running_img_mute, 124, 220);
	lv_obj_set_size(ui->screen_running_img_mute, 72, 18);

	//Write style for screen_running_img_mute, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_mute, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_btn_b_long
	ui->screen_running_btn_b_long = lv_btn_create(ui->screen_running);
	ui->screen_running_btn_b_long_label = lv_label_create(ui->screen_running_btn_b_long);
	lv_label_set_text(ui->screen_running_btn_b_long_label, "");
	lv_label_set_long_mode(ui->screen_running_btn_b_long_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_running_btn_b_long_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_running_btn_b_long, 0, LV_STATE_DEFAULT);
	lv_obj_set_pos(ui->screen_running_btn_b_long, 124, 219);
	lv_obj_set_size(ui->screen_running_btn_b_long, 73, 21);

	//Write style for screen_running_btn_b_long, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_running_btn_b_long, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_running_btn_b_long, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_running_btn_b_long, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_running_btn_b_long, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_running_btn_b_long, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_running_btn_b_long, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_running_btn_b_long, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_running_btn_b_long, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_running_img_status_none
	ui->screen_running_img_status_none = lv_img_create(ui->screen_running);
	lv_obj_add_flag(ui->screen_running_img_status_none, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_running_img_status_none, &_output_none_alpha_94x26);
	lv_img_set_pivot(ui->screen_running_img_status_none, 50,50);
	lv_img_set_angle(ui->screen_running_img_status_none, 0);
	lv_obj_set_pos(ui->screen_running_img_status_none, 226, 0);
	lv_obj_set_size(ui->screen_running_img_status_none, 94, 26);
	lv_obj_add_flag(ui->screen_running_img_status_none, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_running_img_status_none, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_running_img_status_none, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	
	//The custom code of screen_running.
	// lv_obj_remove_style(guider_ui.screen_running_label_v_0, NULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
	// lv_obj_remove_style(guider_ui.screen_running_label_v_1, NULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
	// lv_obj_remove_style(guider_ui.screen_running_label_v_2, NULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
	// lv_obj_remove_style(guider_ui.screen_running_label_v_3, NULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
	// lv_obj_remove_style(guider_ui.screen_running_label_v_4, NULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
	// lv_obj_remove_style(guider_ui.screen_running_label_i_0, NULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
	// lv_obj_remove_style(guider_ui.screen_running_label_i_1, NULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
	// lv_obj_remove_style(guider_ui.screen_running_label_i_2, NULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
	// lv_obj_remove_style(guider_ui.screen_running_label_i_3, NULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
	// lv_obj_remove_style(guider_ui.screen_running_label_i_4, NULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
	

	lv_group_add_obj(group_running, guider_ui.screen_running_label_v_0);
	lv_group_add_obj(group_running, guider_ui.screen_running_label_v_1);
	lv_group_add_obj(group_running, guider_ui.screen_running_label_v_2);
	lv_group_add_obj(group_running, guider_ui.screen_running_label_v_3);
	lv_group_add_obj(group_running, guider_ui.screen_running_label_v_4);
	lv_group_add_obj(group_running, guider_ui.screen_running_label_i_0);
	lv_group_add_obj(group_running, guider_ui.screen_running_label_i_1);
	lv_group_add_obj(group_running, guider_ui.screen_running_label_i_2);
	lv_group_add_obj(group_running, guider_ui.screen_running_label_i_3);
	lv_group_add_obj(group_running, guider_ui.screen_running_label_i_4);

	lv_indev_set_group(indev_keypad, group_running);

	lv_obj_add_event_cb(guider_ui.screen_running_label_v_0, event_vol_current_setting_callback, LV_EVENT_ALL, NULL);		
	lv_obj_add_event_cb(guider_ui.screen_running_label_v_1, event_vol_current_setting_callback, LV_EVENT_ALL, NULL);		
	lv_obj_add_event_cb(guider_ui.screen_running_label_v_2, event_vol_current_setting_callback, LV_EVENT_ALL, NULL);		
	lv_obj_add_event_cb(guider_ui.screen_running_label_v_3, event_vol_current_setting_callback, LV_EVENT_ALL, NULL);		
	lv_obj_add_event_cb(guider_ui.screen_running_label_v_4, event_vol_current_setting_callback, LV_EVENT_ALL, NULL);		
	lv_obj_add_event_cb(guider_ui.screen_running_label_i_0, event_vol_current_setting_callback, LV_EVENT_ALL, NULL);		
	lv_obj_add_event_cb(guider_ui.screen_running_label_i_1, event_vol_current_setting_callback, LV_EVENT_ALL, NULL);		
	lv_obj_add_event_cb(guider_ui.screen_running_label_i_2, event_vol_current_setting_callback, LV_EVENT_ALL, NULL);		
	lv_obj_add_event_cb(guider_ui.screen_running_label_i_3, event_vol_current_setting_callback, LV_EVENT_ALL, NULL);		
	lv_obj_add_event_cb(guider_ui.screen_running_label_i_4, event_vol_current_setting_callback, LV_EVENT_ALL, NULL);		

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_running);

	//Init events for screen.
	events_init_screen_running(ui);
}
