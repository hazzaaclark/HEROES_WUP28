/* Copyright (C) 2023 Harry Clark */

/* dinput8 Implementation of WUP-028 for Sonic Heroes */

/* THIS FILE PERTAINS TO THE FUNCTIONALITY OF THE WUP-028 DRIVER */

/* NESTED INCLUDES */

#include "wup028.h"

#ifdef INIT_WUP28

/* INITALISE THE DRIVER BASED ON THE PRE-DIRECTIVES */
/* THE STRUCTURES WILL ALLOW ME TO USE DMA TO ALLOC MEMORY */
/* ONTO THE STACK BASED ON THE HEX VALUES DESIGNATED TO THE MACROS */

static inline void INIT_DRIVER(DEVICE::HANDLER* HANDLER, PAD::STATUS* STATUS)
{

#ifdef USE_WUP_LIB

	calloc(1, sizeof(HANDLER));
	calloc(1, sizeof(STATUS) + WUP_SUCCESS);
	return;

#endif

}

static void FREE_DRIVER(DEVICE* DEVICE)
{
	free(DEVICE);
}

#endif
