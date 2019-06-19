/*
 * Test Zig4.c
 *
 * Created: 5/2/2019 11:30:17 PM
 * Author : ABCD
 */ 

#include <avr/io.h>
#include "sensor.h"
#include <avr/delay.h>
#define set_bit(port,bit) (port |= (1<<bit))
#define clr_bit(port,bit) (port &=~(1<<bit))
#define bit_is_clear(sfr,bit) (!(_SFR_BYTE(sfr) & _BV(bit)))
#define bit_is_set(sfr,bit)   (_SFR_BYTE(sfr) & _BV(bit))
char data;
int main(void)
{
	DDRH |=(1<<LED1_G);
	DDRG |= (1<<LED3_G);
	DDRE |=((1<<LED1_R)|(1<<LED2_G)|(1<<LED2_R));
	DDRF |=((1<<LED3_R)|(1<<LED4_G)|(1<<LED4_R));
    /* Replace with your application code */
    while (1) 
    {
		data = SENSOR1_PORT_IN;
		if(data&(1<<SENSOR1_IN))
		{
			set_bit(LED1_PORT_G,LED1_G);
			clr_bit(LED1_PORT_R,LED1_R);
		}else
		{
			set_bit(LED1_PORT_R,LED1_R);
			clr_bit(LED1_PORT_G,LED1_G);
		}
		data = SENSOR2_PORT_IN;
		if(data&(1<<SENSOR2_IN))
		{
			set_bit(LED2_PORT_G,LED2_G);
			clr_bit(LED2_PORT_R,LED2_R);
		}else
		{
			set_bit(LED2_PORT_R,LED2_R);
			clr_bit(LED2_PORT_G,LED2_G);
		}
		data = SENSOR3_PORT_IN;
		if(data&(1<<SENSOR3_IN))
		{
			set_bit(LED3_PORT_G,LED3_G);
			clr_bit(LED3_PORT_R,LED3_R);
		}else
		{
			set_bit(LED3_PORT_R,LED3_R);
			clr_bit(LED3_PORT_G,LED3_G);
		}
		data = SENSOR4_PORT_IN;
		if(data&(1<<SENSOR4_IN))
		{
			set_bit(LED4_PORT_G,LED4_G);
			clr_bit(LED4_PORT_R,LED4_R);
		}else
		{
			set_bit(LED4_PORT_R,LED4_R);
			clr_bit(LED4_PORT_G,LED4_G);
		}
		_delay_ms(10);
    }
}

