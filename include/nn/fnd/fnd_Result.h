#pragma once

#include <nn/Result.h>

namespace nn {
namespace fnd {

enum Description
{
        DESCRIPTION_UNK1 = 1,
        DESCRIPTION_UNK2 = 2
};

#define _NN_FND_RESULT_DEF_CONST(result, level, summary, description) \
        NN_RESULT_DEF_CONST (result, Result::level, Result::summary, Result::MODULE_NN_FND, description)

_NN_FND_RESULT_DEF_CONST (ResultInvalidAddress, LEVEL_USAGE, SUMMARY_INVALID_ARGUMENT, DESCRIPTION_INVALID_ADDRESS);

_NN_FND_RESULT_DEF_CONST (ResultFntUnk0, LEVEL_USAGE, SUMMARY_INVALID_ARGUMENT, DESCRIPTION_UNK2);

} // namespace fnd
} // namespace nn
