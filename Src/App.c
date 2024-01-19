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

#define USERNAME_SIZE 16
#define PASSWORD_SIZE 4
#define MAX_USERS 10

// Structure to hold user information
typedef struct {
	char username[USERNAME_SIZE + 1];  // Increased size to accommodate null-terminator
	char password[PASSWORD_SIZE + 1];  // Increased size to accommodate null-terminator
} User;

// Function to verify the entered credentials
int VerifyCredentials(const char* enteredUsername, const char* enteredPassword, const User* user) {
	return (strcmp(enteredUsername, user->username) == 0 &&
			strcmp(enteredPassword, user->password) == 0 &&
			strlen(enteredPassword) == PASSWORD_SIZE);
}

int main(void) {
	MDIO_voidInit();
	MUART_voidInit();
	MTIMER0_voidInit();
	MTIMER1_voidInit();
	MTIMER0_voidSetOCR0Value(0);

	HLCD_voidInit();

	u8 local_u8ReceivedData = 255;
	int attempts = 3,counter=3;

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

	// Buffer to store user input
	char enteredUsername[USERNAME_SIZE + 1];
	char enteredPassword[PASSWORD_SIZE + 1];

	// Send a welcome message
	MUART_voidSendStringSyncNonBlocking("Welcome to the Smart Home System!\r\n\r\n");
	HLCD_voidDisplayString("Welcome Home...");
	while(1){
		// Loop until the correct credentials are entered or maximum attempts reached
		MUART_voidSendStringSyncNonBlocking("Enter username: ");
		MUART_voidReceiveStringSync(enteredUsername);

		MUART_voidSendStringSyncNonBlocking("\r\nEnter password: ");
		MUART_voidReceiveStringSync(enteredPassword);

		// Check if the entered credentials are correct

		for (int i = 0; i < MAX_USERS; ++i) {
			if (VerifyCredentials(enteredUsername, enteredPassword, &validUsers[i])) {
				while(1){
					MUART_voidSendStringSyncNonBlocking("\r\n");
					MUART_voidSendStringSyncNonBlocking("To Turn ON the FirstRoom Press 1\r\nTo Turn OFF the FirstRoom Press 2\r\n");
					MUART_voidSendStringSyncNonBlocking("\r\nTo Turn ON the SecondRoom Press 3\r\nTo Turn OFF the SecondRoom Press 4\r\n");
					MUART_voidSendStringSyncNonBlocking("\r\nTo Turn ON the ThirdRoom Press 5\r\nTo Turn OFF the ThirdRoom Press 6\r\n");
					MUART_voidSendStringSyncNonBlocking("\r\nTo Turn ON the FourthRoom Press 7\r\nTo Turn OFF the FourthRoom Press 8\r\n");
					MUART_voidSendStringSyncNonBlocking("\r\nTo Open The Door Press o or O\r\nTo Close The Door Press c or C\r\n\r\n");

					HLCD_voidClearDisplay();
					local_u8ReceivedData = MUART_u8ReadByteSyncBlocking();

					switch(local_u8ReceivedData)
					{

					//first room
					case '1':

						MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
						MUART_voidSendStringSyncNonBlocking("\r\n\r\nAccess Granted!\r\n\r\n");
						MUART_voidSendStringSyncNonBlocking("\r\n");
						HLED_voidTurnOn(DIO_PORTD, PIN2);
						MUART_voidSendStringSyncNonBlocking("Light ROOM1 ON\r\n");
						HLCD_voidDisplayString("Light ROOM1 ON");
						break;
					case '2':

						MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
						MUART_voidSendStringSyncNonBlocking("\r\n\r\nAccess Granted!\r\n\r\n");
						MUART_voidSendStringSyncNonBlocking("\r\n");
						HLED_voidTurnOff(DIO_PORTD, PIN2);
						MUART_voidSendStringSyncNonBlocking("Light ROOM1 OFF\r\n");
						HLCD_voidDisplayString("Light ROOM2 OFF");

						break;

						//second room
					case '3':

						MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
						MUART_voidSendStringSyncNonBlocking("\r\n\r\nAccess Granted!\r\n\r\n");
						MUART_voidSendStringSyncNonBlocking("\r\n");
						HLED_voidTurnOn(DIO_PORTD, PIN3);
						MUART_voidSendStringSyncNonBlocking("Light ROOM2 ON\r\n");
						HLCD_voidDisplayString("Light ROOM2 ON");

						break;
					case '4':

						MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
						MUART_voidSendStringSyncNonBlocking("\r\n\r\nAccess Granted!\r\n\r\n");
						MUART_voidSendStringSyncNonBlocking("\r\n");
						HLED_voidTurnOff(DIO_PORTD, PIN3);
						MUART_voidSendStringSyncNonBlocking("Light ROOM2 OFF\r\n");
						HLCD_voidDisplayString("Light ROOM2 OFF");

						break;

						//third room
					case '5':

						MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
						MUART_voidSendStringSyncNonBlocking("\r\n\r\nAccess Granted!\r\n\r\n");
						MUART_voidSendStringSyncNonBlocking("\r\n");
						HLED_voidTurnOn(DIO_PORTD, PIN4);
						MUART_voidSendStringSyncNonBlocking("Light ROOM3 ON\r\n");
						HLCD_voidDisplayString("Light ROOM3 ON");

						break;
					case '6':


						MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
						MUART_voidSendStringSyncNonBlocking("\r\n\r\nAccess Granted!\r\n\r\n");
						MUART_voidSendStringSyncNonBlocking("\r\n");
						HLED_voidTurnOff(DIO_PORTD, PIN4);
						MUART_voidSendStringSyncNonBlocking("Light ROOM3 OFF\r\n");
						HLCD_voidDisplayString("Light ROOM3 OFF");

						break;

						//fourth room
					case '7':

						MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
						MUART_voidSendStringSyncNonBlocking("\r\n\r\nAccess Granted!\r\n\r\n");
						MUART_voidSendStringSyncNonBlocking("\r\n");
						HLED_voidTurnOn(DIO_PORTD, PIN6);
						MUART_voidSendStringSyncNonBlocking("Light ROOM4 ON\r\n");
						HLCD_voidDisplayString("Light ROOM4 ON");

						break;
					case '8':

						MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
						MUART_voidSendStringSyncNonBlocking("\r\n\r\nAccess Granted!\r\n\r\n");
						MUART_voidSendStringSyncNonBlocking("\r\n");
						HLED_voidTurnOff(DIO_PORTD, PIN6);
						MUART_voidSendStringSyncNonBlocking("Light ROOM4 OFF\r\n");
						HLCD_voidDisplayString("Light ROOM4 OFF");

						break;
						//the door
					case 'o':
					case 'O':

						MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
						MUART_voidSendStringSyncNonBlocking("\r\n\r\nAccess Granted!\r\n\r\n");
						MUART_voidSendStringSyncNonBlocking("\r\n");
						MTIMER1_voidSetOCR1AValue(1000);
						MUART_voidSendStringSyncNonBlocking("Door Is Opened\r\n");
						HLCD_voidDisplayString("Door Is Opened");

						break;
					case 'c':
					case 'C':
						MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
						MUART_voidSendStringSyncNonBlocking("\r\n\r\nAccess Granted!\r\n\r\n");
						MUART_voidSendStringSyncNonBlocking("\r\n");
						MTIMER1_voidSetOCR1AValue(2000);
						MUART_voidSendStringSyncNonBlocking("Door Is Cloosed\r\n");
						HLCD_voidDisplayString("Door Is Cloosed");

						break;

					default:
					{
						MDIO_voidSetPinDirection(DIO_PORTB,PIN3,DIO_OUTPUT);
						MUART_voidSendByteSyncBlocking(local_u8ReceivedData);
						MUART_voidSendStringSyncNonBlocking("\r\n");
						MUART_voidSendStringSyncNonBlocking("Its wrong chois pleas try again.\r\n");
						MTIMER0_voidSetOCR0Value(10000);
						MDIO_voidSetPinDirection(DIO_PORTB,PIN3,DIO_INPUT);
						attempts--;
					}

					_delay_ms(400);
					HLCD_voidClearDisplay();
					if (attempts == 0) {
						MDIO_voidSetPinDirection(DIO_PORTB,PIN3,DIO_OUTPUT);
						MTIMER0_voidSetOCR0Value(200);
						_delay_ms(300);
						MTIMER0_voidSetOCR0Value(0);
						_delay_ms(300);
						MTIMER0_voidSetOCR0Value(200);
						_delay_ms(300);
						MTIMER0_voidSetOCR0Value(0);
						_delay_ms(300);
						MTIMER0_voidSetOCR0Value(200);
						_delay_ms(300);
						MTIMER0_voidSetOCR0Value(0);
						MDIO_voidSetPinDirection(DIO_PORTB,PIN3,DIO_INPUT);
						attempts=3;
					}

					}
				}

			}


		}
		// If no user matched, show access denied message
		MUART_voidSendStringSyncNonBlocking("\r\n\r\nUsername Or Password incorrect.Please try again.\r\n\r\n");
		HLCD_voidDisplayString("Access Denied!\r\n\r\n");

	}
	return 0;
}
