#include "i2c_rgbw.h"

int main(void) {
    RGBW_Init(); 

    RGBW_AllOnOff(1);

    RGBW_SetColor(255, 128, 0, 0); 

    RGBW_SetBrightness(0, 128); 
    RGBW_SetBrightness(1, 64);  
    RGBW_SetBrightness(2, 192); 
    RGBW_SetBrightness(3, 255); 

    RGBW_ChannelOnOff(0, 0);

    RGBW_SetAllBrightness(100);

    while (1) {
       
    }
}
