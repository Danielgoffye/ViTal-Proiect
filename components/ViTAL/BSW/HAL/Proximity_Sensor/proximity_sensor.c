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
#include"BSW/HAL/Proximity_Sensor/proximity_sensor.h"
static const char *TAG = "PROXIMITY SENSOR";

void PROX_vRequest()
{
    GPIO_vSetLevel(HC_SR04_TRIGGER_PIN, HIGH_LEVEL);
    ets_delay_us(10);
    GPIO_vSetLevel(HC_SR04_TRIGGER_PIN, LOW_LEVEL);
} 

uint16_t PROX_u16Read(void)
{
    uint16_t var_time = 0;
    uint16_t dist = 0;
    while(GPIO_iGetLevel(HC_SR04_ECHO_PIN == LOW_LEVEL))
    {
        var_time = esp_timer_get_time();
    }
    while (GPIO_iGetLevel(HC_SR04_ECHO_PIN) == HIGH_LEVEL)
    {
         dist = (0.0343 * (esp_timer_get_time() - var_time)) / 2;
    }   
    return dist; 
} 

void Afis_dist(void)
{
    uint16_t dist = 0;
    PROX_vRequest();
	dist = PROX_u16Read();
	ESP_LOGI(TAG, "dist = %d", dist);
}