/* Copyright (C) 2023 Harry Clark */

/* dinput8 Implementation of WUP-028 for Sonic Heroes */

/* THIS FILE PERTAINS TO THE FUNCTIONALITY OF THE WUP-028 DRIVER */

#ifndef WUP_028
#define WUP_028

/* NESTED INCLUDES */

#include "common.h"
#include "dinput.h"

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

#define WUP_ALIGN __attribute__((aligned(32)))
#define WUP_PORT                             4
#define WUP_TRIGGER                        170

#define WUP_ERROR_NONE                       0
#define WUP_ERROR_NO_CONNECTION             -1
#define WUP_ERROR                           -2        

#define WUP_BRA                              U32

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

/* TAKING INTO ACCOUNT THE IPC SCHEMA FROM THE WII */
/* IPC DICTATES THE FUNCTIONALITY THAT SERVES AS THE IO FOR THE WII */
/* DETERMINING THE FLAGS AND REGISTERS AND IRQ'S NECESSARY FOR HARDWARE INITIALISATION */

/* THE FOLLOWING IS THE IPC VECTOR TABLE */
/* SEE: https://github.com/dolphin-emu/dolphin/blob/4e46be951a3872b03352c82e4aa3def27de4f124/Source/Core/Core/IPC_HLE/WII_IPC_HLE.h */

#define IPC_SUCCESS                          (1 << 0)
#define IPC_DENIED                           (1 << -1)
#define IPC_FILE                             (1 << -2)
#define IPC_INVALID_ARG                      (1 << -4)
#define IPC_NF                               (1 << -6)
#define IPC_BUSY                             (1 << -8)
#define IPC_EIO                              (1 << -12)
#define IPC_ALLOC_FAIL                       (1 << -22)
#define IPC_FATAL                            (1 << -101)
#define IPC_PERM_DENIED                      (1 << -102)

#define IPC_OPEN_NONE                                                       0
#define IPC_OPEN_READ                                                       1
#define IPC_OPEN_WRITE                                                      2
#define IPC_OPEN_RW(READ, WRITE)             (IPC_OPEN_READ + IPC_OPEN_WRITE)



/* CREATE A MASTER STRUCTURE FOR THE IPC BUS' FUNCTIONALITY */
/* THIS PERTAINS TO THE ACCESS OF USER INPUTS AND THEIR RESPECTIVE RESULTS */

typedef struct IPC
{
	typedef void PAD_INIT(void);
	typedef void PAD_READ(IPC_RES* RESULT);
	typedef void PAD_PORT(U32 PAD, U32 CONTROL);
};

typedef struct IPC_RES;
typedef struct PAD_RES;

typedef struct IOS
{
	typedef U32 IOS_DATA;
	typedef U32 IOS_RETURN;

	typedef IOS_DATA IOS_OPEN(const char* FILE_PATH);
	typedef IOS_RETURN IOS_OPEN_ASYNC(const char* PATH, void* USER_DATA);

	typedef U32 CPU_BRA(void);
	static void CPU_BRA_RESTORE(U32 BRA);
};

typedef struct PAD
{
	typedef PAD_RES* PAD_RESULT;
	typedef U8 PAD_ERROR;
	typedef U32 PAD_DATA;
};

#endif
#endif
