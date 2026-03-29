#include <nn/dbg/dbg_Break.h>
#include <nn/svc/svc_Api.h>

RP_SHUTUP

namespace nn {
namespace dbg {
namespace {
var(BreakHandler, s_pBreakHandler) = NULL;

void PrintErrorMessageHeader(nndbgBreakReason reason, const char* filename, int lineno) // 27
{
        // TODO
}

void CallBreakHandler(BreakReason reason, Result* pResult, const char* filename, int lineno, const char* fmt, va_list args) // 42
{
        BreakHandler* pBreakHandler;
        // TODO
}

void CallBreakHandler(nndbgBreakReason reason, nnResult result, const char* filename, int lineno, const char* fmt, va_list args)
{
        Result resultCpp;
        // TODO
}

void CallBreakHandler(nndbgBreakReason reason, const char* filename, int lineno, const char* fmt, va_list args) // 59
{
        // TODO
}

void CallBreakHandler(BreakReason reason) // 64
{
        va_list args;
        // TODO
}

} // namespace
} // namespace dbg
} // namespace nn

extern "C" {

nnResult nndbgBreak(int reason)
{
        // TODO
}

void nndbgPanic()
{
        nn::dbg::Panic();
}

void nndbgBreakWithMessage_(nndbgBreakReason reason, const char* filename, int lineno, const char* fmt, ...) // 53
{
        va_list arg;
        va_start(arg, fmt);
        nn::dbg::PrintErrorMessageHeader(reason, filename, lineno);
        // TODO
}

void nndbgBreakWithTMessage_(nndbgBreakReason reason, const char* filename, int lineno, const char* fmt, ...) // 65
{
        va_list arg;
        // TODO
}

void nndbgBreakWithResultMessage_(nndbgBreakReason reason, nnResult result, const char* filename, int lineno, const char* fmt, ...) // 77
{
        va_list arg;
        // TODO
}

void nndbgBreakWithResultTMessage_(nndbgBreakReason reason, nnResult result, const char* filename, int lineno, const char* fmt, ...) // 90
{
        va_list arg;
        // TODO
}
}

namespace nn {
namespace dbg {

Result Break(BreakReason reason) // 106
{
        return nn::svc::Break(reason);
}

void Panic()
{
}
} // namespace dbg
} // namespace nn

