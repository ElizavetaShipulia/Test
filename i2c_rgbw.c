#include "i2c_rgbw.h"
#include "stm32f3xx_hal.h"

I2C_HandleTypeDef hi2c1;

#define RGBW_I2C_ADDR    (0x20 << 1) 


static uint8_t rgbw_brightness[4] = {0, 0, 0, 0}; 
static uint8_t rgbw_enabled[4] = {0, 0, 0, 0}; 

void RGBW_Init(void) {
    hi2c1.Instance = I2C1;
    
    hi2c1.Init.Timing = 0x10C0ECFF;
    hi2c1.Init.OwnAddress1 = 0;
    hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c1.Init.OwnAddress2 = 0;
    hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
    hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

    if (HAL_I2C_Init(&hi2c1) != HAL_OK) {
        while(1);
    }

    for (int i=0; i<4; i++) {
        rgbw_brightness[i] = 0;
        rgbw_enabled[i] = 0;
    }
    RGBW_UpdateHW();
}

void RGBW_UpdateHW(void) {
    uint8_t tx[4];
    for (int i=0; i<4; i++) {
        tx[i] = rgbw_enabled[i] ? rgbw_brightness[i] : 0;
    }
    HAL_I2C_Mem_Write(&hi2c1, RGBW_I2C_ADDR, 0x00, I2C_MEMADD_SIZE_8BIT, tx, 4, HAL_MAX_DELAY);
}

void RGBW_SetBrightness(uint8_t channel, uint8_t brightness) {
    if (channel > 3) return;
    rgbw_brightness[channel] = brightness;
    if (rgbw_enabled[channel]) {
        RGBW_UpdateHW();
    }
}

void RGBW_ChannelOnOff(uint8_t channel, bool on){
    if (channel > 3) return;
    rgbw_enabled[channel] = (on ? 1 : 0);
    RGBW_UpdateHW();
}

void RGBW_AllOnOff(bool on){
    for (int i=0; i<4; i++) {
        rgbw_enabled[i] = (on ? 1 : 0);
    }
    RGBW_UpdateHW();
}

void RGBW_SetAllBrightness(uint8_t brightness) {
    for (int i=0; i<4; i++) {
        rgbw_brightness[i] = brightness;
    }
    RGBW_UpdateHW();
}

void RGBW_SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
    #ifdef ONLYRGB
        RGBWSetBrightness(0, r);
        RGBWSetBrightness(1, g);
        RGBWSetBrightness(2, b);
    #endif
    }
    
