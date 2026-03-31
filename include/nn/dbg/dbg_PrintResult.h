#pragma once

#include <nn/Result.h>

#ifdef __cplusplus

namespace nn {
namespace dbg {
namespace detail {

void PrintResult (Result result);
void TPrintResult (Result result);

const char* GetLevelString (Result result);
const char* GetModuleString (Result result);
const char* GetSummaryString (Result result);
const char* GetDescriptionString (Result result);
const char* GetResultCommonDescriptionStringImpl (Result result);

} // namespace detail
} // namespace dbg
} // namespace nn

#endif
