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

#include "../SMARTHOME/SMARTHOME_Interface.h"

#define F_CPU 8000000UL

// Set your initial users
User validUsers[MAX_USERS] = {
		{"user0", "0000"},
		{"user1", "1111"},
		{"user2", "2222"},
		{"user3", "3333"},
		{"user4", "4444"},
		{"user5", "5555"},
		{"user6", "6666"},
		{"user7", "7777"},
		{"user8", "8888"},
		{"user9", "9999"}
};
u8 local_u8ReceivedData = 255;
int attempts = 3;

int main(void) {
	MDIO_voidInit();
	MUART_voidInit();
	MTIMER0_voidInit();
	MTIMER1_voidInit();
	HLCD_voidInit();

	Display_WelcomeMessage();

	// Loop until the correct credentials are entered or maximum attempts reached
	do {
		MUART_voidSendStringSyncNonBlocking("\r\nEnter username: ");
		MUART_voidReceiveStringSync(enteredUsername);

		MUART_voidSendStringSyncNonBlocking("\r\nEnter password: ");
		MUART_voidReceiveStringSync(enteredPassword);

		// Check if the entered credentials are correct
		for (int i = 0; i < MAX_USERS; ++i) {
			if (VerifyCredentials(enteredUsername, enteredPassword, &validUsers[i])) {

				MUART_voidSendStringSyncNonBlocking("\r\nAccess Granted!\r\n\r\n");
				HLCD_voidDisplayString("Access Granted!");
				_delay_ms(1000);
				HLCD_voidClearDisplay();

				while(1){
					Display_Menu();
					local_u8ReceivedData = MUART_u8ReadByteSyncBlocking();
					Smart_Home(local_u8ReceivedData);
				}

				_delay_ms(400);
				HLCD_voidClearDisplay();
			}

		}

		attempts--;

		BuzzerOn(10000);
		_delay_ms(500);
		BuzzerOff ();

		WrongInput();

		if (attempts == 0) {
			BuzzerOn(200);
			_delay_ms(300);

			BuzzerOn(0);
			_delay_ms(300);

			BuzzerOn(200);
			_delay_ms(300);

			BuzzerOn(0);
			_delay_ms(300);

			BuzzerOn(200);
			_delay_ms(300);

			BuzzerOff ();

			attempts=3;
		}

	}while(1);
	return 0;
}
