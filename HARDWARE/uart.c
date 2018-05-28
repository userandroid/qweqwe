#include "uart.h"
volatile uint8_t GucRcvNew;
uint8_t GucRcvBuf[10];
uint32_t GulNum;
uint8_t i = 0;
uint8_t sum = 0;
uint8_t a[1];
void uart_init(void)
{
		uint16_t usFdiv;
		LPC_SYSCON->SYSAHBCLKCTRL |= (1 << 16); 
	//	LPC_IOCON->PIO1_6 &= ~0x07;
		LPC_IOCON->PIO1_6 |= 0x01; //配置P1.6 为 RXD
	//	LPC_IOCON->PIO1_7 &= ~0x07;
		LPC_IOCON->PIO1_7 |= 0x01; //配置P1.7 为 TXD
		LPC_SYSCON->SYSAHBCLKCTRL |= (1 << 12);
		LPC_SYSCON->UARTCLKDIV  = 0x01;
		
		LPC_UART->LCR = 0x83; //允许设置波特率
		usFdiv = (SystemCoreClock / LPC_SYSCON ->UARTCLKDIV /16) /UART_BPS;
		LPC_UART->DLM = usFdiv / 256;
		LPC_UART->DLL =  usFdiv%256;
		LPC_UART->LCR = 0x03;
		LPC_UART->FCR = 0x87;
		NVIC_EnableIRQ(UART_IRQn);
		NVIC_SetPriority(UART_IRQn,1);
		LPC_UART->IER = 0x01;


}
void UART_SendByte(int ucDat)
{
		LPC_UART->THR = ucDat;
		while((LPC_UART->LSR & 0x40) == 0);

}
void UART_SendStr(uint8_t const * pucSTR,uint32_t ulNum)
{
		uint32_t i;
		for(i = 0; i < ulNum; i++)
		{
					UART_SendByte(* pucSTR++);
		}
} 
int CTH(char hex)  //将ascii 转换为数字
{
	int s;
	if((hex>=49)&&(hex<=57))
    s = hex - 48;
 	else if((hex>=97)&&(hex<=102))
    s = hex - 87;
	return s;
}

void UART_IRQHandler(void)
{
		GulNum = 0;
		while((LPC_UART->IIR & 0x01) == 0) //判断是否有中断挂起
		{
				switch(LPC_UART->IIR & 0x0E) //判断中断类型
				{
						case 0x04:  //接收中断
						{
								GucRcvNew = 1;
								for(GulNum = 0; GulNum < 6; GulNum++)
								{
										GucRcvBuf[GulNum] = LPC_UART->RBR;
								}
								if(GucRcvNew == 1)
								{
										GucRcvNew = 0;
										//UART_SendStr(GucRcvBuf,GulNum);
										UART_SendByte(GucRcvBuf[0]);
										UART_SendByte(GucRcvBuf[1]);
										UART_SendByte(GucRcvBuf[2]);
										UART_SendByte(GucRcvBuf[3]);
										
									  if(GucRcvBuf[2] == '0' && GucRcvBuf[3] == '0' )
											LPC_GPIO2->DATA = 0x00;
										else
											LPC_GPIO2->DATA = (CTH(GucRcvBuf[2])*16+CTH(GucRcvBuf[3]));
								
								}
								
						}break;
									
							
					/*case 0x0C:
							GucRcvNew = 1;
						while((LPC_UART->LSR & 0x01) == 0x01)
						{
								GucRcvBuf[GulNum] = LPC_UART->RBR;
								GulNum++;
						
						}
									break;*/
						default:
									break;
				}
	
		
		
		}

}

/*
	0000 0001		1   49
  0000 0010		2
  0000 0011		3
	0000 0100		4
	0000 0101 	5
	0000 0110		6
	0000 0111		7
	0000 1000		8
  0000 1001		9   57
	0000 1010		a   97
	0000 1011		b
  0000 1100		c
	0000 1101		d
	0000 1110		e
	0000 1111		f   102
0xff*/
