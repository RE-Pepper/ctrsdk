#pragma once

#include <nn/Result.h>

namespace nn {
namespace srv {

enum Description
{
        DESCRIPTION_FAILED_SYNCHRONIZATION = 1,
        DESCRIPTION_NO_SUCH_HANDLE         = 2,
        DESCRIPTION_ALREADY_EXISTS         = 3,
        DESCRIPTION_NOT_EXISTS             = 4,
        DESCRIPTION_TOO_LONG_SERVICE_NAME  = 5,
        DESCRIPTION_NOT_PERMITTED          = 6,
        DESCRIPTION_INVALID_NAME           = 7,
        DESCRIPTION_BUFFER_OVERFLOW        = 8,
        DESCRIPTION_END
};

inline Result MakePermanentResult (Result::Summary summary, int description) // 44
{
        return MakePermanentResult (summary, Result::MODULE_NN_SRV, description);
}

inline Result MakeInfoResult(Result::Summary summary, int description) // 49
{
        return MakeInfoResult(summary, Result::MODULE_NN_SRV, description);
}

#define _NN_SRV_MAKE_RESULT(Res, Sum, Desc) \
        NN_RESULT_DEF (MakePermanentResult, Res, Result::Sum, Desc)

_NN_SRV_MAKE_RESULT (ResultAlreadyInitialized, SUMMARY_INVALID_STATE, Result::DESCRIPTION_ALREADY_INITIALIZED); // 84

_NN_SRV_MAKE_RESULT (ResultTooLongServiceName, SUMMARY_WRONG_ARGUMENT, DESCRIPTION_TOO_LONG_SERVICE_NAME);

_NN_SRV_MAKE_RESULT (ResultNotInitialized, SUMMARY_INVALID_STATE, Result::DESCRIPTION_NOT_INITIALIZED); // 101

} // namespace srv
} // namespace nn
