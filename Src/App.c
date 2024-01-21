#include <util/delay.h>
#include <string.h>

#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/GI/GI_interface.h"
#include "../Include/MCAL/UART/UART_Interface.h"
#include "../Include/MCAL/TIMERS/TIMERS_Interface.h"
#include "../include/MCAL/TWI/TWI_interface.h"

#include "../Include/HAL/LED/LED_Interface.h"
#include "../Include/HAL/LCD/LCD_Interface.h"
#include "../Include/HAL/EEPROM/EEPROM_Interface.h"

#define F_CPU 8000000UL

int main(void) {
	MDIO_voidInit();
	MUART_voidInit();
	MTIMER0_voidInit();
	MTIMER1_voidInit();
	u8 local_u8ReceivedData = 255;

	HLCD_voidInit();


	HLCD_voidDisplayString("Welcome Home...");
	_delay_ms(1000);
	HLCD_voidClearDisplay();

	while(1){

		local_u8ReceivedData = MUART_u8ReadByteSyncBlocking();

		switch(local_u8ReceivedData)
		{

		//first room
		case '1':

			MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
			MUART_voidSendStringSyncNonBlocking("\r\n");
			HLED_voidTurnOn(DIO_PORTD, PIN2);
			MUART_voidSendStringSyncNonBlocking("Light ROOM1 ON\r\n");
			HLCD_voidDisplayString("Light ROOM1 ON");
			_delay_ms(500);
			HLCD_voidClearDisplay();
			BuzzerOn(10000);
			_delay_ms(1000);
			BuzzerOff ();
			break;

		case '2':

			MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
			MUART_voidSendStringSyncNonBlocking("\r\n");
			HLED_voidTurnOff(DIO_PORTD, PIN2);
			MUART_voidSendStringSyncNonBlocking("Light ROOM1 OFF\r\n");
			HLCD_voidDisplayString("Light ROOM1 OFF");
			_delay_ms(500);
			HLCD_voidClearDisplay();
			BuzzerOn(10000);
			_delay_ms(1000);
			BuzzerOff ();
			break;

			//second room
		case '3':

			MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
			MUART_voidSendStringSyncNonBlocking("\r\n");
			HLED_voidTurnOn(DIO_PORTD, PIN3);
			MUART_voidSendStringSyncNonBlocking("Light ROOM2 ON\r\n");
			HLCD_voidDisplayString("Light ROOM2 ON");
			_delay_ms(500);
			HLCD_voidClearDisplay();
			BuzzerOn(10000);
			_delay_ms(1000);
			BuzzerOff ();
			break;

		case '4':

			MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
			MUART_voidSendStringSyncNonBlocking("\r\n");
			HLED_voidTurnOff(DIO_PORTD, PIN3);
			MUART_voidSendStringSyncNonBlocking("Light ROOM2 OFF\r\n");
			HLCD_voidDisplayString("Light ROOM2 OFF");
			_delay_ms(500);
			HLCD_voidClearDisplay();
			BuzzerOn(10000);
			_delay_ms(1000);
			BuzzerOff ();
			break;

			//third room
		case '5':

			MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
			MUART_voidSendStringSyncNonBlocking("\r\n");
			HLED_voidTurnOn(DIO_PORTD, PIN4);
			MUART_voidSendStringSyncNonBlocking("Light ROOM3 ON\r\n");
			HLCD_voidDisplayString("Light ROOM3 ON");
			_delay_ms(500);
			HLCD_voidClearDisplay();
			BuzzerOn(10000);
			_delay_ms(1000);
			BuzzerOff ();
			break;

		case '6':


			MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
			MUART_voidSendStringSyncNonBlocking("\r\n");
			HLED_voidTurnOff(DIO_PORTD, PIN4);
			MUART_voidSendStringSyncNonBlocking("Light ROOM3 OFF\r\n");
			HLCD_voidDisplayString("Light ROOM3 OFF");
			_delay_ms(500);
			HLCD_voidClearDisplay();
			BuzzerOn(10000);
			_delay_ms(1000);
			BuzzerOff ();
			break;

			//fourth room
		case '7':

			MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
			MUART_voidSendStringSyncNonBlocking("\r\n");
			HLED_voidTurnOn(DIO_PORTD, PIN6);
			MUART_voidSendStringSyncNonBlocking("Light ROOM4 ON\r\n");
			HLCD_voidDisplayString("Light ROOM4 ON");
			_delay_ms(500);
			HLCD_voidClearDisplay();
			BuzzerOn(10000);
			_delay_ms(1000);
			BuzzerOff ();
			break;

		case '8':

			MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
			MUART_voidSendStringSyncNonBlocking("\r\n");
			HLED_voidTurnOff(DIO_PORTD, PIN6);
			MUART_voidSendStringSyncNonBlocking("Light ROOM4 OFF\r\n");
			HLCD_voidDisplayString("Light ROOM4 OFF");
			_delay_ms(500);
			HLCD_voidClearDisplay();
			BuzzerOn(10000);
			_delay_ms(1000);
			BuzzerOff ();
			break;

			//the door
		case 'o':
		case 'O':

			MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
			MUART_voidSendStringSyncNonBlocking("\r\n");
			MTIMER1_voidSetOCR1AValue(1000);
			MUART_voidSendStringSyncNonBlocking("Door Is Opened\r\n");
			HLCD_voidDisplayString("Door Is Opened");
			_delay_ms(500);
			HLCD_voidClearDisplay();
			BuzzerOn(10000);
			_delay_ms(1000);
			BuzzerOff ();
			break;

		case 'c':
		case 'C':

			MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
			MUART_voidSendStringSyncNonBlocking("\r\n");
			MTIMER1_voidSetOCR1AValue(2000);
			MUART_voidSendStringSyncNonBlocking("Door Is Cloosed\r\n");
			HLCD_voidDisplayString("Door Is Cloosed");
			_delay_ms(500);
			HLCD_voidClearDisplay();
			BuzzerOn(10000);
			_delay_ms(1000);
			BuzzerOff ();
			break;


		case 'b':
			BuzzerOn(200);
			_delay_ms(300);

			BuzzerOff ();
			_delay_ms(300);

			BuzzerOn(200);
			_delay_ms(300);

			BuzzerOff ();
			_delay_ms(300);

			BuzzerOn(200);
			_delay_ms(300);

			BuzzerOff ();

			break;
		}
	}
}
