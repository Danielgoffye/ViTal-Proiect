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

#include "BSW/HAL/Servo_Motor/servo_motor.h"
#include "RTE/rte.h"


static const char *TAG = "SERVO_MOTOR";
#define Servo_Motor_0 500
#define Servo_Motor_1 1600
#define Servo_Motor_2 3200
uint8_t test1 = 1;

void SERVO_vChangeAngle(uint32_t u32ServoAngle)
{
  if(RTE_bGET_ServoMotorStatus())
    {if(u32ServoAngle == 0 && test1 ==1)
      {
          PWM_vSetDutyCycle(SERVO_MOTOR_PWM_CHANNEL, Servo_Motor_0);
          test1 = 0;
          ESP_LOGI(TAG, "temp_var = %d", test1);
      }
      else
      {
        PWM_vSetDutyCycle(SERVO_MOTOR_PWM_CHANNEL, 0);
      }
    if(u32ServoAngle == 90 && test1 ==1)
    {
         PWM_vSetDutyCycle(SERVO_MOTOR_PWM_CHANNEL, Servo_Motor_1);
         test1 = 90;
                   ESP_LOGI(TAG, "temp_var = %d", test1);
    }
    else
      {
        PWM_vSetDutyCycle(SERVO_MOTOR_PWM_CHANNEL, 0);
      }
     if(u32ServoAngle == 180 && test1 ==1)
    {
        test1 = 180;
          PWM_vSetDutyCycle(SERVO_MOTOR_PWM_CHANNEL, Servo_Motor_2);
                    ESP_LOGI(TAG, "temp_var = %d", test1);
    } 
    else
      {
        PWM_vSetDutyCycle(SERVO_MOTOR_PWM_CHANNEL, 0);
      }
    }
    else if(!RTE_bGET_ServoMotorStatus())
      {
        PWM_vSetDutyCycle(SERVO_MOTOR_PWM_CHANNEL, 0);
      }
}
