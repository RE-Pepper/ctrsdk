#pragma once

#include <nn/Result.h>

namespace nn {
namespace srv {

enum Description
{
        DESCRIPTION_FAILED_SYNCHRONIZATION,
        DESCRIPTION_NO_SUCH_HANDLE,
        DESCRIPTION_ALREADY_EXISTS,
        DESCRIPTION_NOT_EXISTS,
        DESCRIPTION_TOO_LONG_SERVICE_NAME,
        DESCRIPTION_NOT_PERMITTED,
        DESCRIPTION_INVALID_NAME,
        DESCRIPTION_BUFFER_OVERFLOW,
        DESCRIPTION_END
};

inline Result
MakePermanentResult (Result::Summary summary, int description) // 44
{
        return MakePermanentResult (summary, Result::MODULE_NN_SRV, description);
}

inline Result MakeInfoResult(Result::Summary summary, int description) // 49
{
        return MakeInfoResult(summary, Result::MODULE_NN_SRV, description);
}

#define _NN_SRV_MAKE_RESULT_P(Res, Sum, Desc)                   \
        inline Result Res ()                                    \
        {                                                       \
                return MakePermanentResult (Result::Sum, Desc); \
        }

_NN_SRV_MAKE_RESULT_P (ResultAlreadyInitialized, SUMMARY_INVALID_STATE, Result::DESCRIPTION_ALREADY_INITIALIZED); // 84

_NN_SRV_MAKE_RESULT_P (ResultTooLongServiceName, SUMMARY_WRONG_ARGUMENT, DESCRIPTION_TOO_LONG_SERVICE_NAME);

_NN_SRV_MAKE_RESULT_P (ResultNotInitialized, SUMMARY_INVALID_STATE, Result::DESCRIPTION_NOT_INITIALIZED); // 101

} // namespace srv
} // namespace nn
