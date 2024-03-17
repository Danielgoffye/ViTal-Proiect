/*******************************************************************************
 * COPYRIGHT (C) VITESCO TECHNOLOGIES
 * ALL RIGHTS RESERVED.
 *
 * The reproduction, transmission or use of this document or its
 * contents is not permitted without express written authority.
 * Offenders will be liable for damages. All rights, including rights
 * created by patent grant or registration of a utility model or design,
 * are reserved.
 *******************************************************************************/

#include "BSW/HAL/Buzzer/buzzer.h"
#define buzzer_0 200

void BUZZER_vChangeDutyCycle(uint32_t u32BuzzerDutyCycle)
{
    if(u32BuzzerDutyCycle == 0)
    {
         PWM_vSetDutyCycle(BUZZER_PWM_CHANNEL, 0);
    }
    else
    {
        PWM_vSetDutyCycle(BUZZER_PWM_CHANNEL, buzzer_0);
    }
}