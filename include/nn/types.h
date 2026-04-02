#pragma once

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
// Base type definitions

typedef unsigned char      u8;  // 51
typedef unsigned short     u16; // 53
typedef unsigned int       u32; // 55
typedef unsigned long long u64; // 57
typedef signed char        s8;  // 60
typedef signed short       s16; // 62
typedef signed int         s32; // 64
typedef signed long long   s64; // 66

typedef uintptr_t uptr; // 71

typedef char    char8;  // 74
typedef wchar_t char16; // 76

typedef volatile u8  vu8;  //
typedef volatile u16 vu16; //
typedef volatile u32 vu32; // 80
typedef volatile u64 vu64; //

typedef volatile s8  vs8;  //
typedef volatile s16 vs16; // 84
typedef volatile s32 vs32; // 85
typedef volatile s64 vs64; //

typedef float  f32; // 89
typedef double f64; // 91

typedef unsigned char      bit8;  // 97
typedef unsigned short     bit16; // 99
typedef unsigned int       bit32; // 101
typedef unsigned long long bit64; // 103

#ifdef __cplusplus

namespace nn {

typedef bit64 ProgramId; // 126

struct ProductInfo
{
        char  productCode[16];
        bit16 companyCode;
        u16   remasterVersion;
};

} // namespace nn

// C++03 didnt have nullptr yet
#ifndef nullptr
#define nullptr NULL
#endif

#endif

#ifndef NN_PACK
#define NN_PACK __attribute__ ((__packed__))
#endif

#ifndef NN_UNUSED
#define NN_UNUSED __attribute__ ((unused))
#endif

// this file is included by project_global.h

