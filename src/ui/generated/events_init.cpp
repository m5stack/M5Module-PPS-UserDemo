/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#include "main.h"
#include "lvgl_porting.h"

#if LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

uint8_t setting_voltage_current_index = 0;
uint8_t output_flag = 0;
uint8_t voice_flag = 1;
voltage_current_setting_t voltage_current_set;

void select_voltage_current(void);
void set_output(void);
void set_voice(void);
void setting_voltage_current_add(uint8_t index);
void setting_voltage_current_reduce(uint8_t index);

static lv_timer_t *standby_update_data_task;
static lv_timer_t *running_update_data_task;
static lv_timer_t *flash_timer;
static void screen_standby_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		standby_update_data_task = lv_timer_create(screen_standby_timer_cb, 100, &guider_ui);
		flash_timer = lv_timer_create(flash_timer_cb, 10, &guider_ui);
		page_number = PAGE_STANDBY;
		break;
	}
	case LV_EVENT_SCREEN_UNLOADED:
	{
		lv_timer_del(standby_update_data_task);
		break;
	}
	default:
		break;
	}
}
static void screen_standby_cont_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		// set voltage
		// beep();
		// set_voltage();
		break;
	}
	default:
		break;
	}
}
static void screen_standby_cont_2_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		// set current
		// beep();
		// set_current();
		break;
	}
	default:
		break;
	}
}
static void screen_standby_btn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		// set output
		// beep();
		// set_output();
		break;
	}
	default:
		break;
	}
}
static void screen_standby_btn_2_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		beep();
		M5.update();
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_running, guider_ui.screen_running_del, &guider_ui.screen_standby_del, setup_scr_screen_running, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, false, true);
		break;
	}
	default:
		break;
	}
}
void events_init_screen_standby(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_standby, screen_standby_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_standby_cont_1, screen_standby_cont_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_standby_cont_2, screen_standby_cont_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_standby_btn_1, screen_standby_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_standby_btn_2, screen_standby_btn_2_event_handler, LV_EVENT_ALL, NULL);
}
static void screen_running_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		running_update_data_task = lv_timer_create(screen_running_timer_cb, 100, &guider_ui);
		page_number = PAGE_RUNNING;
		memset(&voltage_current_set, 0, sizeof(voltage_current_set));
		break;
	}
	case LV_EVENT_SCREEN_UNLOADED:
	{
		lv_timer_del(running_update_data_task);
		break;
	}
	default:
		break;
	}
}
static void screen_running_cont_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		// set voltage
		beep();
		select_voltage_current();		
		break;
	}
	default:
		break;
	}
}
static void screen_running_cont_2_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		// set current
		beep();
		select_voltage_current();		
		break;
	}
	default:
		break;
	}
}
static void screen_running_btn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		// set output
		beep();
		set_output();
		break;
	}
	default:
		break;
	}
}
static void screen_running_btn_a_short_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		// btnA short
		beep();
		if (output_flag == 0) {
			select_voltage_current();
		}
		else {
			set_output();
		}		
		break;
	}
	default:
		break;
	}
}
static void screen_running_btn_b_short_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		// btnB short
		beep();
		setting_voltage_current_add(setting_voltage_current_index);		
		break;
	}
	default:
		break;
	}
}
static void screen_running_btn_c_short_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		// btnC short
		beep();
		setting_voltage_current_reduce(setting_voltage_current_index);		
		break;
	}
	default:
		break;
	}
}
static void screen_running_btn_c_long_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		// btnC long
		break;
	}
	default:
		break;
	}
}
static void screen_running_btn_b_long_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		//btnB long
		beep();
		if (output_flag == 0) {
			set_voice();
		}
		else {
			select_voltage_current();
		}			
		break;
	}
	default:
		break;
	}
}
static void screen_running_btn_a_long_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		// btnA long
		beep();
		set_output();		
		break;
	}
	default:
		break;
	}
}
void events_init_screen_running(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_running, screen_running_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_running_cont_1, screen_running_cont_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_running_cont_2, screen_running_cont_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_running_btn_1, screen_running_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_running_btn_a_short, screen_running_btn_a_short_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_running_btn_b_short, screen_running_btn_b_short_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_running_btn_c_short, screen_running_btn_c_short_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_running_btn_c_long, screen_running_btn_c_long_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_running_btn_b_long, screen_running_btn_b_long_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->screen_running_btn_a_long, screen_running_btn_a_long_event_handler, LV_EVENT_ALL, NULL);
}

void events_init(lv_ui *ui)
{

}

void hidden_current_sel(void)
{
	lv_obj_add_flag(guider_ui.screen_running_img_i_0_0, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_running_img_i_0_1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_running_img_i_1_0, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_running_img_i_1_1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_running_img_i_2_0, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_running_img_i_2_1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_running_img_i_3_0, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_running_img_i_3_1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_running_img_i_4_0, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_running_img_i_4_1, LV_OBJ_FLAG_HIDDEN);	
}

void hidden_voltage_sel(void)
{
	lv_obj_add_flag(guider_ui.screen_running_img_v_0_0, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_running_img_v_0_1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_running_img_v_1_0, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_running_img_v_1_1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_running_img_v_2_0, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_running_img_v_2_1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_running_img_v_3_0, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_running_img_v_3_1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_running_img_v_4_0, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(guider_ui.screen_running_img_v_4_1, LV_OBJ_FLAG_HIDDEN);	
}

void show_voltage_current_sel(void)
{
	switch (setting_voltage_current_index)
	{
	case 0:
		lv_obj_clear_flag(guider_ui.screen_running_img_v_0_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_running_img_v_0_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_1_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_1_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_2_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_2_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_3_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_3_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_4_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_4_1, LV_OBJ_FLAG_HIDDEN);		

		hidden_current_sel();
		break;
	case 1:
		lv_obj_clear_flag(guider_ui.screen_running_img_v_1_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_running_img_v_1_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_0_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_0_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_2_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_2_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_3_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_3_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_4_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_4_1, LV_OBJ_FLAG_HIDDEN);

		hidden_current_sel();
		break;
	case 2:
		lv_obj_clear_flag(guider_ui.screen_running_img_v_2_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_running_img_v_2_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_0_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_0_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_1_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_1_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_3_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_3_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_4_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_4_1, LV_OBJ_FLAG_HIDDEN);

		hidden_current_sel();
		break;
	case 3:
		lv_obj_clear_flag(guider_ui.screen_running_img_v_3_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_running_img_v_3_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_0_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_0_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_1_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_1_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_2_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_2_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_4_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_4_1, LV_OBJ_FLAG_HIDDEN);

		hidden_current_sel();
		break;
	case 4:
		lv_obj_clear_flag(guider_ui.screen_running_img_v_4_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_running_img_v_4_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_0_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_0_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_1_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_1_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_2_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_2_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_3_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_v_3_1, LV_OBJ_FLAG_HIDDEN);

		hidden_current_sel();
		break;

	case 5:
		lv_obj_clear_flag(guider_ui.screen_running_img_i_0_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_running_img_i_0_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_1_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_1_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_2_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_2_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_3_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_3_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_4_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_4_1, LV_OBJ_FLAG_HIDDEN);

		hidden_voltage_sel();
		break;
	case 6:
		lv_obj_clear_flag(guider_ui.screen_running_img_i_1_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_running_img_i_1_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_0_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_0_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_2_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_2_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_3_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_3_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_4_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_4_1, LV_OBJ_FLAG_HIDDEN);

		hidden_voltage_sel();
		break;
	case 7:
		lv_obj_clear_flag(guider_ui.screen_running_img_i_2_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_running_img_i_2_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_0_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_0_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_1_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_1_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_3_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_3_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_4_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_4_1, LV_OBJ_FLAG_HIDDEN);

		hidden_voltage_sel();
		break;
	case 8:
		lv_obj_clear_flag(guider_ui.screen_running_img_i_3_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_running_img_i_3_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_0_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_0_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_1_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_1_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_2_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_2_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_4_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_4_1, LV_OBJ_FLAG_HIDDEN);

		hidden_voltage_sel();
		break;
	case 9:
		lv_obj_clear_flag(guider_ui.screen_running_img_i_4_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_running_img_i_4_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_0_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_0_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_1_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_1_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_2_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_2_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_3_0, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_i_3_1, LV_OBJ_FLAG_HIDDEN);

		hidden_voltage_sel();
		break;
	
	default:
		break;
	}	
}

void select_voltage_current(void)
{
	setting_voltage_current_index++;
	if (setting_voltage_current_index > 9) {
		setting_voltage_current_index = 0;
	}

	show_voltage_current_sel();
}

void show_voltage_current_setting()
{
	lv_label_set_text_fmt(guider_ui.screen_running_label_v_0, "%d", voltage_current_set.vol_0);
	lv_label_set_text_fmt(guider_ui.screen_running_label_v_1, "%d", voltage_current_set.vol_1);
	lv_label_set_text_fmt(guider_ui.screen_running_label_v_2, "%d", voltage_current_set.vol_2);
	lv_label_set_text_fmt(guider_ui.screen_running_label_v_3, "%d", voltage_current_set.vol_3);
	lv_label_set_text_fmt(guider_ui.screen_running_label_v_4, "%d", voltage_current_set.vol_4);

	lv_label_set_text_fmt(guider_ui.screen_running_label_i_0, "%d", voltage_current_set.cur_0);
	lv_label_set_text_fmt(guider_ui.screen_running_label_i_1, "%d", voltage_current_set.cur_1);
	lv_label_set_text_fmt(guider_ui.screen_running_label_i_2, "%d", voltage_current_set.cur_2);
	lv_label_set_text_fmt(guider_ui.screen_running_label_i_3, "%d", voltage_current_set.cur_3);
	lv_label_set_text_fmt(guider_ui.screen_running_label_i_4, "%d", voltage_current_set.cur_4);
}

void setting_voltage_current_add(uint8_t index)
{
	switch (index)
	{
	case 0:
		if (voltage_current_set.vol_0 < 3)
			voltage_current_set.vol_0++;
		break;
	case 1:
		if (voltage_current_set.vol_1 < 9)
			voltage_current_set.vol_1++;
		else {
			setting_voltage_current_add(index-1);
			voltage_current_set.vol_1 = 0;
		}
		break;
	case 2:
		if (voltage_current_set.vol_2 < 9)
			voltage_current_set.vol_2++;
		else {
			setting_voltage_current_add(index-1);
			voltage_current_set.vol_2 = 0;
		}
		break;
	case 3:
		if (voltage_current_set.vol_3 < 9)
			voltage_current_set.vol_3++;
		else {
			setting_voltage_current_add(index-1);
			voltage_current_set.vol_3 = 0;
		}
		break;
	case 4:
		if (voltage_current_set.vol_4 < 9)
			voltage_current_set.vol_4++;
		else {
			setting_voltage_current_add(index-1);
			voltage_current_set.vol_4 = 0;
		}			
		break;
	case 5:
		voltage_current_set.cur_0 = 0;
		break;
	case 6:
		if (voltage_current_set.cur_1 < 5)
			voltage_current_set.cur_1++;
		break;
	case 7:
		if (voltage_current_set.cur_2 < 9)
			voltage_current_set.cur_2++;
		else {
			setting_voltage_current_add(index-1);
			voltage_current_set.cur_2 = 0;
		}				
		break;
	case 8:
		if (voltage_current_set.cur_3 < 9)
			voltage_current_set.cur_3++;
		else {
			setting_voltage_current_add(index-1);
			voltage_current_set.cur_3 = 0;
		}			
		break;
	case 9:
		if (voltage_current_set.cur_4 < 9)
			voltage_current_set.cur_4++;
		else {
			setting_voltage_current_add(index-1);
			voltage_current_set.cur_4 = 0;
		}			
		break;
	
	default:
		break;
	}

	if (voltage_current_set.vol_0 == 3) {
		voltage_current_set.vol_1 = 0;
		voltage_current_set.vol_2 = 0;
		voltage_current_set.vol_3 = 0;
		voltage_current_set.vol_4 = 0;
	}
	if (voltage_current_set.cur_1 == 5) {
		voltage_current_set.cur_2 = 0;
		voltage_current_set.cur_3 = 0;
		voltage_current_set.cur_4 = 0;
	}

	show_voltage_current_setting();

	float voltage_setting = voltage_current_set.vol_0 * 10.0f + (float)voltage_current_set.vol_1 + \
	voltage_current_set.vol_2 * 0.1f + voltage_current_set.vol_3 * 0.01f + voltage_current_set.vol_4 * 0.001f;
	float current_setting = voltage_current_set.cur_0 * 10.0f + (float)voltage_current_set.cur_1 + \
	voltage_current_set.cur_2 * 0.1f + voltage_current_set.cur_3 * 0.01f + voltage_current_set.cur_4 * 0.001f;

	pps.setOutputVoltage(voltage_setting);
	pps.setOutputCurrent(current_setting);
}

void setting_voltage_current_reduce(uint8_t index)
{
	switch (index)
	{
	case 0:
		if (voltage_current_set.vol_0 > 0)
			voltage_current_set.vol_0--;
		break;
	case 1:
		if (voltage_current_set.vol_1 > 0)
			voltage_current_set.vol_1--;
		else {
			if (voltage_current_set.vol_0) {
				setting_voltage_current_reduce(index-1);
				voltage_current_set.vol_1 = 9;
			}
		}
		break;
	case 2:
		if (voltage_current_set.vol_2 > 0)
			voltage_current_set.vol_2--;
		else {
			if (voltage_current_set.vol_0 || voltage_current_set.vol_1) {
				setting_voltage_current_reduce(index-1);
				voltage_current_set.vol_2 = 9;
			}
		}			
		break;
	case 3:
		if (voltage_current_set.vol_3 > 0)
			voltage_current_set.vol_3--;
		else {
			if (voltage_current_set.vol_0 || voltage_current_set.vol_1 || voltage_current_set.vol_2) {
				setting_voltage_current_reduce(index-1);
				voltage_current_set.vol_3 = 9;
			}
		}			
		break;
	case 4:
		if (voltage_current_set.vol_4 > 0)
			voltage_current_set.vol_4--;
		else {
			if (voltage_current_set.vol_0 || voltage_current_set.vol_1 || voltage_current_set.vol_2 || 
			voltage_current_set.vol_3) {
				setting_voltage_current_reduce(index-1);
				voltage_current_set.vol_4 = 9;
			}
		}				
		break;
	case 5:
		voltage_current_set.cur_0 = 0;
		break;
	case 6:
		if (voltage_current_set.cur_1 > 0)
			voltage_current_set.cur_1--;
		break;
	case 7:
		if (voltage_current_set.cur_2 > 0)
			voltage_current_set.cur_2--;
		else {
			if (voltage_current_set.cur_1) {
				setting_voltage_current_reduce(index-1);
				voltage_current_set.cur_2 = 9;
			}
		}				
		break;
	case 8:
		if (voltage_current_set.cur_3 > 0)
			voltage_current_set.cur_3--;
		else {
			if (voltage_current_set.cur_1 || voltage_current_set.cur_2) {
				setting_voltage_current_reduce(index-1);
				voltage_current_set.cur_3 = 9;
			}
		}			
		break;
	case 9:
		if (voltage_current_set.cur_4 > 0)
			voltage_current_set.cur_4--;
		else {
			if (voltage_current_set.cur_1 || voltage_current_set.cur_2 || voltage_current_set.cur_3) {
				setting_voltage_current_reduce(index-1);
				voltage_current_set.cur_4 = 9;
			} 
		}				
		break;
	
	default:
		break;
	}

	if (voltage_current_set.vol_0 == 3) {
		voltage_current_set.vol_1 = 0;
		voltage_current_set.vol_2 = 0;
		voltage_current_set.vol_3 = 0;
		voltage_current_set.vol_4 = 0;
	}
	if (voltage_current_set.cur_1 == 5) {
		voltage_current_set.cur_2 = 0;
		voltage_current_set.cur_3 = 0;
		voltage_current_set.cur_4 = 0;
	}	

	show_voltage_current_setting();

	float voltage_setting = voltage_current_set.vol_0 * 10.0f + (float)voltage_current_set.vol_1 + \
	voltage_current_set.vol_2 * 0.1f + voltage_current_set.vol_3 * 0.01f + voltage_current_set.vol_4 * 0.001f;
	float current_setting = voltage_current_set.cur_0 * 10.0f + (float)voltage_current_set.cur_1 + \
	voltage_current_set.cur_2 * 0.1f + voltage_current_set.cur_3 * 0.01f + voltage_current_set.cur_4 * 0.001f;
	
	pps.setOutputVoltage(voltage_setting);
	pps.setOutputCurrent(current_setting);	
}

void set_output(void)
{
	if (output_flag) {
		output_flag = 0;
		lv_obj_add_flag(guider_ui.screen_running_img_output_enable, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_running_img_output_diabled, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_running_img_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_5, LV_OBJ_FLAG_HIDDEN);	
		if (!voice_flag) {
			lv_obj_add_flag(guider_ui.screen_running_img_mute, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(guider_ui.screen_running_img_loud, LV_OBJ_FLAG_HIDDEN);
		}
		else {
			lv_obj_add_flag(guider_ui.screen_running_img_loud, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(guider_ui.screen_running_img_mute, LV_OBJ_FLAG_HIDDEN);
		}		
		pps.setPowerEnable(false);
	}
	else {
		output_flag = 1;
		lv_obj_add_flag(guider_ui.screen_running_img_output_diabled, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_running_img_output_enable, LV_OBJ_FLAG_HIDDEN);	
		lv_obj_clear_flag(guider_ui.screen_running_img_5, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(guider_ui.screen_running_img_1, LV_OBJ_FLAG_HIDDEN);
		if (!voice_flag) {
			lv_obj_add_flag(guider_ui.screen_running_img_mute, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(guider_ui.screen_running_img_loud, LV_OBJ_FLAG_HIDDEN);
		}
		else {
			lv_obj_add_flag(guider_ui.screen_running_img_loud, LV_OBJ_FLAG_HIDDEN);
			lv_obj_clear_flag(guider_ui.screen_running_img_mute, LV_OBJ_FLAG_HIDDEN);
		}
		pps.setPowerEnable(true);		
	}
}

void set_voice(void)
{
	if (voice_flag) {
		voice_flag = 0;
		lv_obj_add_flag(guider_ui.screen_running_img_mute, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_running_img_loud, LV_OBJ_FLAG_HIDDEN);
	}
	else {
		voice_flag = 1;
		lv_obj_add_flag(guider_ui.screen_running_img_loud, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_running_img_mute, LV_OBJ_FLAG_HIDDEN);
	}
}

void event_vol_current_setting_callback(lv_event_t *event)
{
    lv_obj_t *obj = lv_event_get_current_target(event);
    lv_event_code_t code = lv_event_get_code(event);

	if (code == LV_EVENT_FOCUSED) {
		select_voltage_current();
	}
	else if (code == LV_EVENT_KEY) {
		uint32_t key_code = lv_indev_get_key(indev_keypad);
		switch (key_code)
		{
		case LV_KEY_RIGHT:
			setting_voltage_current_add(setting_voltage_current_index);
			break;
		case LV_KEY_LEFT:
			setting_voltage_current_reduce(setting_voltage_current_index);
			break;
		case KEYPAD_P:
			set_output();
			break;
		case KEYPAD_S:
			set_voice();
			break;
		
		default:
			break;
		}
	}
}