#include "i2c_rgbw.h"

int main(void) {
    RGBW_Init(); // Инициализация I2C и микросхемы управления светодиодами
    // Включаем все каналы:
    RGBW_AllOnOff(1);

    RGBW_SetColor(255, 128, 0, 0); 
    // Установливаем разную яркость каналов
    RGBW_SetBrightness(0, 128); 
    RGBW_SetBrightness(1, 64);  
    RGBW_SetBrightness(2, 192); 
    RGBW_SetBrightness(3, 255); 
    // Выключить только красный (R)
    RGBW_ChannelOnOff(0, 0);
    // Установливаем одну яркость для всех
    RGBW_SetAllBrightness(100);

    while (1) {
       
    }
}
