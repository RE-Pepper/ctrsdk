#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

#ifndef NULL
#define NULL (void*)0
#endif

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

typedef signed char        s8;
typedef signed short       s16;
typedef signed int         s32;
typedef signed long long   s64;

typedef float              f32;
typedef double             f64;

#ifdef __cplusplus

#ifndef nullptr
#define nullptr NULL
#endif

typedef u32 uintptr_t;
typedef s32 intptr_t;

#endif

#ifndef static_assert
#define static_assert( COND, MSG ) typedef int __static_assert_balls[ ( COND ) ? 1 : -1 ]
#endif

// without this static data cannot be referenced in the linker map
#define split( S ) __attribute__( ( section( ".sdata_" #S ) ) ) S

