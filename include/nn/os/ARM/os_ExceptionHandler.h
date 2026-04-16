#pragma once

#include <nn/util/util_SizedEnum.h>

namespace nn {
namespace os {
namespace ARM {

enum ExceptionType
{
        EXCEPTION_TYPE_PABT    = 0,
        EXCEPTION_TYPE_DABT    = 1,
        EXCEPTION_TYPE_UNDEF   = 2,
        EXCEPTION_TYPE_VFP     = 3,
        EXCEPTION_TYPE_MAX_BIT = 128
};

struct ExceptionContext
{
        bit32 r[16];
        bit32 cpsr;
};

struct ExceptionInfo
{
        util::SizedEnum1<ExceptionType> type;
        NN_PAD_24;

        bit32 fsr;
        bit32 far;
        bit32 fpexc;
        bit32 fpinst;
        bit32 fpinst2;
};

typedef void (*UserExceptionHandler)();

namespace detail {
void SaveThreadLocalRegionAddress();
}

void SetUserExceptionHandler(UserExceptionHandler pHandler, uptr stackBottom);

} // namespace ARM
} // namespace os
} // namespace nn
