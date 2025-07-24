#ifndef __SERIAL_H
#define __SERIAL_H

#include <stdio.h>
#include <stdarg.h>
//#include "stm32h7xx_hal.h"

#define USART_REC_LEN  			1500  	//定义最大接收字节数 200

#define RXBUFFERSIZE   1 //缓存大小



#define FB_ON (uint8_t)1
#define FB_OFF (uint8_t)0

extern UART_HandleTypeDef *huart_screen;
extern UART_HandleTypeDef *huart_debug;
extern uint8_t USART4_RX_BUF[USART_REC_LEN];     //接收缓冲,最大USART_REC_LEN个字节.
extern uint16_t USART4_RX_STA;       //接收状态标记


extern uint8_t USART5_RX_BUF[USART_REC_LEN];     //接收缓冲,最大USART_REC_LEN个字节.
extern uint16_t USART5_RX_STA;       //接收状态标记


void Serial_SendByte(uint8_t Byte);
void Serial_SendByte_t(uint8_t Byte,UART_HandleTypeDef *huart);

void Serial_SendArr(uint8_t *array,uint16_t length);
void Serial_SendArr_t(uint8_t *array,uint16_t length,UART_HandleTypeDef *huart);

uint32_t Serial_Power(uint32_t base,uint32_t exp);
void Serial_SendNum(uint32_t num);

void Serial_SendStr(char *string);
void Serial_SendStr_t(char *string,UART_HandleTypeDef *huart);

void Serial_printf(const char *formatted,...);

void Screen_SendArr(uint8_t *array,uint16_t length);
void Screen_SendStr(char *string,uint8_t FB);
void Screen_SendStr_b(char *string);
void Screen_SendArrToShow(uint8_t *array,uint16_t length,uint8_t FB);
void Screen_SendStrToShow(char *string,uint8_t FB);
void Screen_SendNum(uint32_t num);
void Screen_SendNumToShow(uint32_t num);

void print2serial(void);
void print2screen(void);

#endif
