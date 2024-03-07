/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


#ifndef EVENTS_INIT_H_
#define EVENTS_INIT_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"

void events_init(lv_ui *ui);

void events_init_screen_standby(lv_ui *ui);
void events_init_screen_running(lv_ui *ui);

struct voltage_current_setting_t
{
    uint8_t vol_0;
    uint8_t vol_1;
    uint8_t vol_2;
    uint8_t vol_3;
    uint8_t vol_4;
    uint8_t cur_0;
    uint8_t cur_1;
    uint8_t cur_2;
    uint8_t cur_3;
    uint8_t cur_4;
};


void event_vol_current_setting_callback(lv_event_t *event);

extern uint8_t output_flag;
extern uint8_t voice_flag;

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
