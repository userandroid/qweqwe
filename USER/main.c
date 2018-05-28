#include "led.h"
#include "uart.h"

int b = 1;
int main(void)
{
	led_init();
	uart_init();
	while(1)
	{
		//LPC_GPIO2->DATA = 254;
	}
}

