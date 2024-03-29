/*
 * DIO_INTERFACE.h
 *
 * Created: 9/6/2022 11:33:12 AM
 *  Author: Ahmed Eldeeb
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN_OUTPUT	1
#define DIO_PIN_INPUT	0

#define DIO_PORT_OUTPUT	0xff
#define DIO_PORT_INPUT	0x00

#define DIO_PORT_HIGH	0xff
#define DIO_PORT_LOW	0x00

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_PIN_LOW	 0
#define DIO_PIN_HIGH 1

void DIO_SetPinDirection	(u8 PortId,u8 PinId,u8 PinDirection );
void DIO_SetPinValue		(u8 PortId,u8 PinId,u8 PinValue);
void DIO_GetPinValue		(u8 PortId,u8 PinId,u8* PinValue);
void DIO_TogglePinValue		(u8 PortId,u8 PinId);
void DIO_setInputPinResistance(u8 PortId, u8 PinId);

void DIO_SetPortDirection	(u8 PortId,u8 PortDirection );
void DIO_SetPortValue		(u8 PortId,u8 PortValue);
void DIO_GetPortValue		(u8 PortId,u8* PortValue);
void DIO_TogglePortValue	(u8 PortId);
void DIO_setInputPortResistance(u8 PortId);

#endif /* DIO_INTERFACE_H_ */