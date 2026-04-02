#pragma once

#include <nn/Result.h>

RP_SHUTUP

namespace nn {
namespace os {
namespace CTR {
namespace detail {

void HandleInternalError (Result result, const char* filename, int lineno);
void HandleInternalError (Result result);

void SetInternalErrorHandlingMode (bool preferFatal);

// Is this really from here?
#define NN_OS_HANDLE_ERROR(result)                                                                \
        Result nn_os_result = (result);                                                           \
        if (nn_os_result.IsFailure ()) {                                                          \
                nn::os::CTR::detail::HandleInternalError (nn_os_result, __BASE_FILE__, __LINE__); \
        }

} // namespace detail
} // namespace CTR
} // namespace os
} // namespace nn
