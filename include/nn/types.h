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

// Macros

#ifndef NN_PACK
#define NN_PACK __attribute__ ((__packed__))
#endif

#ifndef NN_UNUSED
#define NN_UNUSED __attribute__ ((unused))
#endif

// Project helpers

#ifndef RP_SHUTUP
#define RP_SHUTUP \
        _Pragma ("diag_suppress 177,550,940")
#endif

// Assertion
#ifndef static_assert
#define static_assert(COND, MSG) typedef int __static_assert_failed[(COND) ? 1 : -1]
#endif
#define static_assert_(COND) static_assert (COND, #COND)

#ifdef __arm__

// without this static data cannot be referenced in the linker map
#define var(Type, Name) static Type __attribute__ ((section (".sdata_" #Name))) Name
// same for assembly functions
#define asm_ext(Name, Sect) __asm __attribute__ ((section (Sect))) Name
#define asm(Name) asm_ext (Name, "i." #Name)

#else
#define var(Type, Name) Type Name
#define asm_ext(Name, Sect) Name
#define asm(Name) Name

#define __weak
#endif
