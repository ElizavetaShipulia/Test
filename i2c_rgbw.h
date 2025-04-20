#ifndef I2C_RGBW_H
#define I2C_RGBW_H

#include <stdint.h>
#include <stdbool.h>
#define ONLYRGB 

void RGBW_SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t w);
// Инициализация
void RGBW_Init(void);
void RGBW_UpdateHW(void);
// Установка цвета
void RGBW_SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t w);
// Управление яркостью по каждому каналу отдельно
void RGBW_SetRed(uint8_t value);
void RGBW_SetGreen(uint8_t value);
void RGBW_SetBlue(uint8_t value);
void RGBW_SetWhite(uint8_t value);
// Включение/выключение каналов по отдельности
void RGBW_ChannelOn(char channel);   
void RGBW_ChannelOff(char channel);
// Включение/выключение всех каналов одновременно
void RGBW_AllOn(void);
void RGBW_AllOff(void);
// Получение текущего значения яркости по каждому каналу
uint8_t RGBW_GetRed(void);
uint8_t RGBW_GetGreen(void);
uint8_t RGBW_GetBlue(void);
uint8_t RGBW_GetWhite(void);

void RGBW_ChannelOnOff(uint8_t channel, bool on);
// Включение/выключение всех каналов одной функцией
void RGBW_AllOnOff(bool on);
// Управление яркостью любого канала
void RGBW_SetBrightness(uint8_t channel, uint8_t value);
// Установка одной и той же яркости сразу на все каналы
void RGBW_SetAllBrightness(uint8_t value);

#endif
