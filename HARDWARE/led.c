#include "led.h"
#include "LPC11xx.h"

void led_init()
{
	int i;
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16); //��IOCON
	LPC_IOCON->PIO2_0 &= ~0x07;    //��λ
	LPC_IOCON->PIO2_0 |= 0x00;     //����
	LPC_IOCON->PIO2_1 &= ~0x07;	
	LPC_IOCON->PIO2_1 |= 0x00;  
	LPC_IOCON->PIO2_2 &= ~0x07;    
	LPC_IOCON->PIO2_2 |= 0x00;  
	LPC_IOCON->PIO2_3 &= ~0x07;	
	LPC_IOCON->PIO2_3 |= 0x00; 
	LPC_IOCON->PIO2_4 &= ~0x07;    
	LPC_IOCON->PIO2_4 |= 0x00;  
	LPC_IOCON->PIO2_5 &= ~0x07;	
	LPC_IOCON->PIO2_5 |= 0x00; 
	LPC_IOCON->PIO2_6 &= ~0x07;    
	LPC_IOCON->PIO2_6 |= 0x00;  
	LPC_IOCON->PIO2_7 &= ~0x07;	
	LPC_IOCON->PIO2_7 |= 0x00; 
	
	LPC_IOCON->PIO3_5 &= ~0x07;    
	LPC_IOCON->PIO3_5 |= 0x00;  

	LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16); //�ر�IOCON
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);
	for(i=0;i<=7;i++)    //����2_0 �� 2_7 ����Ϊ��� ��ƽΪ��
	{ 
			LPC_GPIO2->DIR |= (1<<i);  
			LPC_GPIO2->DATA |= (1<<i);
	
	}
	LPC_GPIO3->DIR |= (1 << 5);
	LPC_GPIO3->DATA |= (1 << 5);
}



