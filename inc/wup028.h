/* Copyright (C) 2023 Harry Clark */

/* dinput8 Implementation of WUP-028 for Sonic Heroes */

/* THIS FILE PERTAINS TO THE FUNCTIONALITY OF THE WUP-028 DRIVER */

#ifndef WUP_028
#define WUP_028

/* NESTED INCLUDES */

#include "common.h"
#include "detours.h"

/* SYSTEM INCLUDES */

#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

#if defined(INIT_WUP28)
#define INIT_WUP28 
#else
#define INIT_WUP28

#define WUP_ID                             0x57E03337 /* HARDWARE ID PROVIDED BY DEVICE MANAGER */
#define WUP_SIZE                           0x25

#define WUP_ALIGN                          __attribute__((aligned(32)))
#define WUP_PORT                             4
#define WUP_TRIGGER                        170

#define WUP_SUCCESS                          0
#define WUP_ERROR_NO_CONNECTION             -1
#define WUP_ERROR_ACCESS                    -2
#define WUP_ERROR_IO                        -3
#define WUP_ERROR_NOT_DETECTED              -4

#define WUP_ENDPOINT_IN                    0x80
#define WUP_ENDPOINT_OUT                   0x00

/* DEFINE THE TIME IN MILLISECONDS TO REPRESENT THE DISCONNECTION */

#define WUP_TIME *(243000/4)
#define WUP_DISCONNECT (1500 WUP_TIME)

#define WUP_PAD_LEFT                           0x0001
#define WUP_PAD_RIGHT                          0x0002
#define WUP_PAD_DOWN                           0x0004
#define WUP_PAD_UP                             0x0008
#define WUP_PAD_Z                              0x0010
#define WUP_PAD_R                              0x0020
#define WUP_PAD_L                              0x0040
#define WUP_PAD_A                              0x0100
#define WUP_PAD_B                              0x0200
#define WUP_PAD_X                              0x0400
#define WUP_PAD_Y                              0x0800
#define WUP_PAD_START                          0x1000
 
#define WUP_NOT_CONNECTED                           0
#define WUP_CONNECTED                               1

#endif

#if defined(WUP_DEVICE)
#define WUP_DEVICE
#else
#define WUP_DEVICE

typedef struct DEVICE
{
	static U8 FLAGS;
	static U32 DATA_BUFF_LENGTH;
	typedef union HANDLER;
};

typedef struct DEVICE_CFG
{
	static U8 ENDPOINTS;
	static U8 ADDRESS;
	static DEVICE* CONFIGURE_DEVICE;
	static U32* SETTINGS;
};

typedef struct PAD
{
	typedef union STATUS
	{
		static U16 BUTTTON;
		static U8 STICK_X;
		static U8 STICK_Y;
		static U8 CSTICK_X;
		static U8 CSTICK_Y;
		static U8 LT;
		static U8 RT;
		static U8 ANALOG_A;
		static U8 ANALOG_B;
		static bool CONNECTED;
	};

	typedef U8 PAD_ERROR;
};

#ifdef USE_WUP_LIB
#define USE_WUP_LIB
#else
#define USE_WUP_LIB

static bool(*CHECK_ACCESS(DEVICE* DEVICE));
typedef void(*ADD_WUP_ADAPTER(DEVICE* DEVICE));

typedef U32* INPUT_CALLBACK;
typedef U32 GET_CONFIG_DESCRIPTOR(DEVICE DEVICE, U8 VALUE);

static void FREE_SCAN(void);
static void RESET_ADAPTER(void);

#endif
#endif

#endif
