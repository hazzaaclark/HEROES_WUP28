/* Copyright (C) 2023 Harry Clark */

/* dinput8 Implementation of WUP-028 for Sonic Heroes */

/* THIS FILE PERTAINS TO THE FUNCTIONALITY OF THE DIRECT INPUT LIBRARY */
/* IN ACCORDANCE WITH THIS PROJECT, SONIC HEROES USES DX8 AS IT'S INPUT MODULE */

#ifndef DINPUT
#define DINPUT

/* NESTED INCLUDES */

#include "common.h"

#define DX_API_CALL              _cdecl
#define DX_API_VER               0x0800
#define DX_API_MODULE            "d3d8.dll"

#if defined(USE_DX_ARGS)
#define USE_DX_ARGS
#else
#define USE_DX_ARGS

#define DECLARE_DX_API(RETURN_TYPE, NAME, ...) RETURN_TYPE (DX_API_CALL *NAME)(__VA_ARGS__) = NULL;

#define DECLARE_DX_VALUE(NAME, VALUES) \
static DX_LOADER* VALUE ## NAME ## VALUES();

/* THIS STRUCTURE HELPS WITH THE CONCATENATION OF INSTANCES */

typedef struct DX_LOADER
{
	DECLARE_DX_API(U32, GET_API_VER);
	DECLARE_DX_API(void*, SIG_SCAN);
	DECLARE_DX_API(void*, SET_STATE);
	DECLARE_DX_API(void*, SET_FLAG);

};

/* THE FOLLOWING ARE THE PRE-DIRECTIVES DEFIEND FOR */
/* THE INPUT DEVICES, THE PITCH AND YAW OF THE INPUTS */
/* AS WELL AS THE TRIGOMETRIC MATHS */

DECLARE_DX_VALUE(DIRECT_INPUT, 0x25E609E0, 0xB259, 0x11CF, 0xBF, 0xC7, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00);
DECLARE_DX_VALUE(DIRECT_INPUT_DEVICE, 0x25E609E1, 0xB259, 0x11CF, 0xBF, 0xC7, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00);


#endif

#endif
