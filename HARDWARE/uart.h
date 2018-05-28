#ifndef __UART_H
#define __UART_H
#include "LPC11xx.H"
#include "stdint.h"
void uart_init(void);
int CTH(char hex);
void UART_SendByte(int ucDat);
void UART_SendStr(uint8_t const  * pucSTR,uint32_t ulNum);
#define UART_BPS 9600

#endif
