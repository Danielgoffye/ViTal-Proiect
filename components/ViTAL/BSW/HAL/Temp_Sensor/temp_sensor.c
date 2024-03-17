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

#include "BSW/HAL/Temp_Sensor/temp_sensor.h"


void DHT11_vRequest(void)
{
    GPIO_vSetDirection(DHT11_PIN, DIR_OUTPUT);
    GPIO_vSetLevel(DHT11_PIN, HIGH_LEVEL);  
    GPIO_vSetLevel(DHT11_PIN, LOW_LEVEL);
    ets_delay_us(18000);
    GPIO_vSetLevel(DHT11_PIN, HIGH_LEVEL);      
}

int DHT11_vResponse(void)
{
        int response = 0;
        GPIO_vSetDirection(DHT11_PIN, DIR_INPUT);
        ets_delay_us(53);
        if (GPIO_iGetLevel(DHT11_PIN) == LOW_LEVEL)  
            {
                ets_delay_us(80);
                if (GPIO_iGetLevel(DHT11_PIN) == HIGH_LEVEL)
                {
                    response = 2;
                }
            }
            return response;
}


// char DHT11_u8Receive(void)
// {
//     static char v[40];
//      GPIO_vSetDirection(DHT11_PIN, DIR_INPUT);
//      for(int i=0; i<40;i++)
//      {  
//          ets_delay_us(53);
//         if (GPIO_iGetLevel(DHT11_PIN) == LOW_LEVEL)  
//         {
//             ets_delay_us(23);
//              if (GPIO_iGetLevel(DHT11_PIN) == HIGH_LEVEL)
//              {
//                  v[i] = '0';
//              }
//             else
//             {
//                 ets_delay_us(46);
//                 if (GPIO_iGetLevel(DHT11_PIN) == HIGH_LEVEL)   
//                 {   
//                     v[i] = '1';
//                  }
//             }   

//         }
//         else
//         {
//             GPIO_vSetLevel(DHT11_PIN, LOW_LEVEL);
//         }
//     }
//     return v;
// }

//   struct temp_senzor
//    {
//        char temp_decim[8];
//        char temp_fr[8];
//        char humidity_decim[8];
//        char humidity_fr[8];
//        char checksum[8]; 
//    };

// void DHT11_dht11Read(void)
// {
//    char temp[40] = DHT11_u8Receive();
//    struct temp_senzor senzor;
//      for (int i = 0; i < 8; i++)
//     {
//         senzor.temp_decim[i] = temp[i];
//     }

//     for (int i = 0; i < 8; i++)
//     {
//         senzor.temp_fr[i] = temp[i + 8];
//     }

//     for (int i = 0; i < 8; i++)
//     {
//         senzor.humidity_decim[i] = temp[i + 16];
//     }

//     for (int i = 0; i < 8; i++)
//     {
//         senzor.humidity_fr[i] = temp[i + 24];
//     }

//     for (int i = 0; i < 8; i++)
//     {
//         senzor.checksum[i] = temp[i + 32];
//     }
// }