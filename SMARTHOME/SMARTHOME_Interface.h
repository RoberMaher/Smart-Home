/*
 * SMARTHOME_Interface.h
 *
 *  Created on: Dec 1, 2023
 *      Author: Rober Maher
 */

#ifndef SMARTHOME_SMARTHOME_INTERFACE_H_
#define SMARTHOME_SMARTHOME_INTERFACE_H_

#define MAX_NUMBER_OF_USERS		  10
#define USER_NAME_MAX_SIZE		  6
#define USER_PASS_MAX_SIZE		  4
u8 Username_trials			  =	  3;
u8 Password_trials			  =	  3;
u8 Username_valid_login_flag  =   0;
u8 Password_valid_login_flag  =   0;

u8 Input_Username[USER_NAME_MAX_SIZE];				//to store username entered by user
u8 Input_Password[USER_PASS_MAX_SIZE];				//to store password entered by user
u8 Username_Password_Index; 		// Used to indicate which password index to look at


typedef struct
{
	u16 userNameAdd;
	u16 userPassAdd;
	u8 userName[USER_NAME_MAX_SIZE];
	u8 userPass[USER_PASS_MAX_SIZE];

}User_e;

User_e USER_ONE =
{
		.userNameAdd = 0x00,
		.userPassAdd = 0x18,
		.userName = "user1",
		.userPass = "1111"
};
User_e USER_TWO =
{
		.userNameAdd = 0x20,
		.userPassAdd = 0x38,
		.userName = "user2",
		.userPass = "2222"
};
User_e USER_THREE =
{
		.userNameAdd = 0x40,
		.userPassAdd = 0x58,
		.userName = "user3",
		.userPass = "3333"
};
User_e USER_FOUR =
{
		.userNameAdd = 0x60,
		.userPassAdd = 0x78,
		.userName = "user4",
		.userPass = "4444"
};
User_e USER_FIVE =
{
		.userNameAdd = 0x80,
		.userPassAdd = 0x98,
		.userName = "user5",
		.userPass = "5555"
};
User_e USER_SIX =
{
		.userNameAdd = 0xA0,
		.userPassAdd = 0xB8,
		.userName = "user6",
		.userPass = "6666"
};
User_e USER_SEVEN =
{
		.userNameAdd = 0xC0,
		.userPassAdd = 0xD8,
		.userName = "user7",
		.userPass = "7777"
};
User_e USER_EGIHT =
{
		.userNameAdd = 0xE0,
		.userPassAdd = 0xF8,
		.userName = "user8",
		.userPass = "8888"
};
User_e USER_NINE =
{
		.userNameAdd = 0x100,
		.userPassAdd = 0x118,
		.userName = "user9",
		.userPass = "9999"
};
User_e USER_TEN =
{
		.userNameAdd = 0x120,
		.userPassAdd = 0x138,
		.userName = "user10",
		.userPass = "1010"
};
User_e *dbAccounts[MAX_NUMBER_OF_USERS] =
{
		&USER_ONE,
		&USER_TWO,
		&USER_THREE,
		&USER_FOUR,
		&USER_FIVE,
		&USER_SIX,
		&USER_SEVEN,
		&USER_EGIHT,
		&USER_NINE,
		&USER_TEN
};

u8 Usernames[MAX_NUMBER_OF_USERS][USER_NAME_MAX_SIZE]={"user1","user2","user3","user4","user5","user6","user7","user8","user9","user10"};
u8 Passwords[MAX_NUMBER_OF_USERS][USER_PASS_MAX_SIZE]={"1111","2222","3333","4444","5555"};
void app_clear_string(u8* Copy_u8InputString, u8 Copy_u8Length);
void app_copy_string(u8* Copy_u8InputString, u8* Copy_u8OutputString, u8 Copy_u8Length);
void Show_Usernames_PWs();
void Save_DataBaseInEEPROM();
void Username(void);


#endif /* SMARTHOME_SMARTHOME_INTERFACE_H_ */
