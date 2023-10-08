/* Copyright (C) 2023 Harry Clark */

/* xinput Implementation of WUP-028 for Sonic Heroes */

/* THIS FILE REPRESENTS THE VIRTUALISATION OF AN XINPUT DEVICE */
/* WHICH WILL INADVERTENTLY WORK IN TANDEM WITH THE ADAPTER TO */
/* MIMICK INPUTS */

/* NESTED INCLUDES */

#include "common.h"

/* SYSTEM INCLUDES */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <Xinput.h>

#if defined(VIRTUAL_PERIPHERAL)
#define VIRTUAL_PERIPHERAL
#else
#define VIRTUAL_PERIPHERAL

#define DECLARE_VIRTUAL_METHOD(RETURN_TYPE, METHOD_NAME, PARAMS) \
	RETURN_TYPE (*METHOD_NAME) PARAMS

typedef struct PERIPHERAL
{
	DECLARE_VIRTUAL_METHOD(DWORD, XInputGetState, (XINPUT_STATE* STATE));
};

#endif