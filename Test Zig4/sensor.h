#ifndef _SENSOR_H_
#define _SENSOR_H_
#include <stdint.h>
#include <avr/io.h>
#define SENSOR_NUMBER 4
#define bit_is_clear(sfr,bit) (!(_SFR_BYTE(sfr) & _BV(bit)))
#define bit_is_set(sfr,bit)   (_SFR_BYTE(sfr) & _BV(bit))
#define SENSOR1_IN 5
#define SENSOR2_IN 6
#define SENSOR3_IN 4
#define SENSOR4_IN 3

#define SENSOR1_PORT_IN PINB
#define SENSOR2_PORT_IN PINB
#define SENSOR3_PORT_IN PINB
#define SENSOR4_PORT_IN PINB

#define LED1_G      0
#define LED1_PORT_G PORTH
#define LED1_R      5
#define LED1_PORT_R PORTE
#define LED2_G      4
#define LED2_PORT_G PORTE
#define LED2_R      3
#define LED2_PORT_R PORTE
#define LED3_G      5
#define LED3_PORT_G PORTG
#define LED3_R      0
#define LED3_PORT_R PORTF
#define LED4_G      1
#define LED4_PORT_G PORTF
#define LED4_R      2
#define LED4_PORT_R PORTF
uint8_t count = 0;
uint8_t Read_Sensor(uint8_t *data_out);
#endif