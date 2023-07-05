/* Copyright (C) 2023 Harry Clark */

/* dinput8 Implementation of WUP-028 for Sonic Heroes */

#ifndef PCH
#define PCH

/* NESTED INCLUDES */

#include <stdio.h>
#include <Psapi.h>

#if defined(WIN_32)
#define WIN_32
#else
#define WIN_32

#include <Windows.h>
#include "dinput.h"

#endif
#endif