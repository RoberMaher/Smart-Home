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

	HLCD_voidInit();

	u8 local_u8ReceivedData = 255;

	HLCD_voidDisplayString("Welcome Home...");
	_delay_ms(1000);
	HLCD_voidClearDisplay();

	while(1){
		Display_Menu();
		local_u8ReceivedData = MUART_u8ReadByteSyncBlocking();
		Smart_Home(local_u8ReceivedData);
	}
}
