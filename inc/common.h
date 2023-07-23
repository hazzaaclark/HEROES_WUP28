/* Copyright (C) 2023 Harry Clark */

/* dinput8 Implementation of WUP-028 for Sonic Heroes */

/* THIS FILE IS ABOUT COMMON DATA TYPES USED THROUGHOUT THE PROJECT */
/* CREATING TYPE DEFINED METHODS TO INSTANTIATE RAW POINTERS FOR MY */
/* METHODS, FUNCTIONS, ETC */


#ifndef COMMON
#define COMMON

#include <cstdint>
#include <limits.h>
#include <stdio.h>

#ifndef UNSIGNED_TYPES
#define UNSIGNED_TYPES

typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;

#endif 

#ifndef SIGNED_TYPES
#define SIGNED_TYPES

typedef int8_t S8;
typedef int16_t S16;
typedef int32_t S32;
typedef int64_t S64;

#endif 

#ifndef UNKNOWN_TYPES
#define UNKNOWN_TYPES

typedef unsigned char UNK_8;
typedef unsigned short UNK_16;
typedef unsigned int UNK_32;
typedef unsigned long UNK_64;
typedef unsigned long UNK_;

#endif

#ifndef FLOATING_POINT
#define FLOATING_POINT 

typedef float F32;
typedef double F64;
typedef volatile F32 VF32;
typedef volatile F64 VF64;

#endif

#ifndef FUNCTIONS
#define FUNCTIONS

#define VOID_FUNCTION(NAME) void NAME() 

#endif

#ifdef USE_BIT_UTILS
#define USE_BIT_UTILS
#else
#define USE_BIT_UTILS

#define BIT_SIZE(VALUE) (sizeof(VALUE) * CHAR_BIT)

#endif

#ifdef __cplusplus
extern "C"
{}
#endif

#endif