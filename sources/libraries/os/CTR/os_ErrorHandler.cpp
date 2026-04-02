#pragma once

#include <nn/os/CTR/os_ErrorHandler.h>

RP_SHUTUP

namespace nn {
namespace os {
namespace CTR {
namespace detail {

namespace {
var(nn::os::CTR::detail, s_PreferFatal, bool) = true;
}

void HandleInternalError (Result result, const char* filename, int lineno)// 31
{
        Result::Level level;
        // TODO
}

void HandleInternalError (Result result) // 68
{
        Result::Level level;
        // TODO
}

void SetInternalErrorHandlingMode (bool preferFatal) // 97
{
        s_PreferFatal = preferFatal;
}

} // namespace detail
} // namespace CTR
} // namespace os
} // namespace nn
