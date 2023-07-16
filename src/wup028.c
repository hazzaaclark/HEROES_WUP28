/* Copyright (C) 2023 Harry Clark */

/* dinput8 Implementation of WUP-028 for Sonic Heroes */

/* THIS FILE PERTAINS TO THE FUNCTIONALITY OF THE WUP-028 DRIVER */

/* NESTED INCLUDES */

#include "wup028.h"

/* CHECK FOR ERROR HANDLING SCHEME UPON INTILISATION */
/* THIS IS TAKING INTO ACCOUNT THE LOAD ASYNCHRONOUS METHOD */
/* BEFORE INITIALISING THE MASTER COMPONENT */

#ifdef INIT_WUP28

static IPC::PAD_INIT* PAD_INIT(IPC::PAD_READ* PAD_READ, PAD::PAD_ERROR* ERROR,
	                                          PAD::PAD_RESULT* RESULT,
	                                          PAD::PAD_DATA* PAD_DATA,
	                                          IOS::IOS_OPEN_ASYNC* OPEN_ASYNC)
{
	for (U32 i = 0; i < WUP_PORT; i++)
	{
		ERROR += WUP_ERROR_NO_CONNECTION;
	}

	OPEN_ASYNC(WUP_PATH, NULL);

	for (U32 j = 0; j < WUP_PORT; j++)
	{
		ERROR += WUP_ERROR_NO_CONNECTION;
		PAD_DATA -= WUP_DISCONNECT;
	}

	if (RESULT += sizeof(ERROR)) WUP_ERROR;
}

/* PREPRIATORY FREE METHOD FOR MEMORY DEALLOCATION */

static void PAD_FREE(IPC::PAD_READ* PAD_READ)
{
	free(PAD_READ);
}

#endif