#ifndef __LED_H
#define __LED_H
#include "LPC11xx.H"

#define LED1_ON()  (LPC_GPIO2->DATA &= ~(1<<0)) 	
#define LED1_OFF() (LPC_GPIO2->DATA |= (1<<0)) 		

#define LED2_ON()  (LPC_GPIO2->DATA &= ~(1<<1)) 	
#define LED2_OFF() (LPC_GPIO2->DATA |= (1<<1)) 	

#define LED3_ON()  (LPC_GPIO2->DATA &= ~(1<<2)) 	
#define LED3_OFF() (LPC_GPIO2->DATA |= (1<<2))

#define LED4_ON()  (LPC_GPIO2->DATA &= ~(1<<3)) 	
#define LED4_OFF() (LPC_GPIO2->DATA |= (1<<3))

#define LED5_ON()  (LPC_GPIO2->DATA &= ~(1<<4)) 	
#define LED5_OFF() (LPC_GPIO2->DATA |= (1<<4))

#define LED6_ON()  (LPC_GPIO2->DATA &= ~(1<<5)) 	
#define LED6_OFF() (LPC_GPIO2->DATA |= (1<<5))

#define LED7_ON()  (LPC_GPIO2->DATA &= ~(1<<6)) 	
#define LED7_OFF() (LPC_GPIO2->DATA |= (1<<6))

#define LED8_ON()  (LPC_GPIO2->DATA &= ~(1<<7)) 	
#define LED8_OFF() (LPC_GPIO2->DATA |= (1<<7))

#define LED0_ON()  (LPC_GPIO3->DATA &= ~(1<<5)) 	
#define LED0_OFF() (LPC_GPIO3->DATA |= (1<<5))
void led_init(void);

#endif





