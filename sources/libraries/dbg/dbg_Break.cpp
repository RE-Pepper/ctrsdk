#include <cstdarg>
#include <nn/dbg/dbg_Break.h>
#include <nn/dbg/dbg_DebugString.h>
#include <nn/dbg/dbg_PrintResult.h>
#include <nn/svc/svc_StubDbg.h>

#include "nn/dbg/dbg_Enum.h"

RP_SHUTUP

namespace nn {
namespace dbg {

namespace {
var(nn::dbg, s_pBreakHandler, BreakHandler) = NULL;
} // namespace

void PrintErrorMessageHeader(nndbgBreakReason reason, const char* filename, int lineno)
{
        detail::TPrintf("----\n");
        if (reason == NN_DBG_BREAK_REASON_ASSERT) {
            detail::TPrintf("Assertion failure at %s:%d\n  ", filename, lineno);
        } else {
            detail::TPrintf("Panic at %s:%d\n  ", filename, lineno);
        }
}

Result Break(BreakReason reason)
{
        return nn::svc::Break(reason);
}

void Panic()
{
        // TODO
}

} // namespace dbg
} // namespace nn

extern "C" {

nnResult nndbgBreak(nndbgBreakReason reason)
{
        return nn::dbg::Break((nn::dbg::BreakReason)reason);
}

void nndbgPanic()
{
        nn::dbg::Panic();
}

void nndbgBreakWithMessage_(nndbgBreakReason reason, const char* filename, int lineno, const char* fmt, ...)
{
        va_list arg;
        va_start(arg, fmt);
        nn::dbg::PrintErrorMessageHeader(reason, filename, lineno);
        nn::dbg::detail::VPrintf(fmt, arg);
        nn::dbg::detail::TPrintf("\n");
        va_end(arg);
        nndbgBreak(reason);
}

void nndbgBreakWithTMessage_(nndbgBreakReason reason, const char* filename, int lineno, const char* fmt, ...)
{
        va_list arg;
        va_start(arg, fmt);
        nn::dbg::PrintErrorMessageHeader(reason, filename, lineno);
        nn::dbg::detail::TVPrintf(fmt, arg);
        nn::dbg::detail::TPrintf("\n");
        va_end(arg);
        nndbgBreak(reason);
}

void nndbgBreakWithResultMessage_(nndbgBreakReason reason, nnResult result, const char* filename, int lineno, const char* fmt, ...)
{
        va_list arg;
        va_start(arg, fmt);
        nn::dbg::PrintErrorMessageHeader(reason, filename, lineno);
        nn::dbg::detail::VPrintf(fmt, arg);
        nn::dbg::detail::TPrintf("\n");
        nn::dbg::detail::PrintResult(result);
        va_end(arg);
        nndbgBreak(reason);
}

void nndbgBreakWithResultTMessage_(nndbgBreakReason reason, nnResult result, const char* filename, int lineno, const char* fmt, ...)
{
        va_list arg;
        va_start(arg, fmt);
        nn::dbg::PrintErrorMessageHeader(reason, filename, lineno);
        nn::dbg::detail::TVPrintf(fmt, arg);
        nn::dbg::detail::TPrintf("\n");
        nn::dbg::detail::TPrintResult(result);
        va_end(arg);
        nndbgBreak(reason);
}
}

