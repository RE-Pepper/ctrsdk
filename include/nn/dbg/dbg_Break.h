#pragma once

#include <nn/Result.h>
#include <nn/dbg/dbg_Enum.h>

#ifdef __cplusplus
extern "C" {
#endif

nnResult nndbgBreak(int reason);
void     nndbgPanic();
void     nndbgBreakWithMessage_(nndbgBreakReason reason, const char* filename, int lineno, const char* fmt, ...);
void     nndbgBreakWithTMessage_(nndbgBreakReason reason, const char* filename, int lineno, const char* fmt, ...);
void     nndbgBreakWithResultMessage_(nndbgBreakReason reason, nnResult result, const char* filename, int lineno, const char* fmt, ...);
void     nndbgBreakWithResultTMessage_(nndbgBreakReason reason, nnResult result, const char* filename, int lineno, const char* fmt, ...);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
namespace nn {
namespace dbg {

typedef void (*BreakHandler)(BreakReason reason, const Result* pResult, const char* filename, int lineno, const char* message, va_list vlist);

Result Break(BreakReason reason);
void   Panic();

inline Result Break()
{
        return Break(BREAK_REASON_PANIC);
}

} // namespace dbg
} // namespace nn

#endif
