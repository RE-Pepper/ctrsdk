#include <cstdio>
#include <nn/module.h>
#include <nn/nstd/nstd_Printf.h>
#include <nn/svc/svc_StubDbg.h>

namespace nn {
namespace dbg {
namespace detail {

namespace {
NN_MAKE_MODULE_SDK (s_UsePutString, "DebugPrint");
}

void PutString (const char* text, int length) // 36
{
        NN_REFER_MODULE (s_UsePutString);
        nn::svc::OutputDebugString (text, length);
}

void PutString (const char* text) // 36
{
        PutString (text, 0);
}

void VPrintf (const char* fmt, va_list arg) // 47
{
        char buf[256];
        int  length = vsnprintf (buf, 256, fmt, arg);
        if (length >= 256) {
                length = 255;
        }

        PutString (buf, length);
}

void TVPrintf (const char* fmt, va_list arg) // 58
{
        char buf[128];
        int  length = nn::nstd::TVSNPrintf (buf, 0x80, fmt, arg);
        if (length >= 128) {
                length = 127;
        }

        PutString (buf, length);
}

void Printf (const char* fmt, ...) // 69
{
        va_list vlist;
        va_start (vlist, fmt);
        VPrintf (fmt, vlist);
        va_end (vlist);
}

void TPrintf (const char* fmt, ...) // 78
{
        va_list vlist;
        va_start (vlist, fmt);
        TVPrintf (fmt, vlist);
        va_end (vlist);
}

} // namespace detail
} // namespace dbg
} // namespace nn

extern "C" {

void nndbgPrintWarning_ (const char* filename, int lineno, const char* fmt, ...) // 126
{
        va_list vlist;
        va_start (vlist, fmt);
        nn::dbg::detail::TPrintf ("%s:%d [WARN] ", filename, lineno);
        nn::dbg::detail::VPrintf (fmt, vlist);
        nn::dbg::detail::TPrintf ("\n");
        va_end (vlist);
}

void nndbgTPrintWarning_ (const char* filename, int lineno, const char* fmt, ...) // 137
{
        va_list vlist;
        va_start (vlist, fmt);
        nn::dbg::detail::TPrintf ("%s:%d [WARN] ", filename, lineno);
        nn::dbg::detail::TVPrintf (fmt, vlist);
        nn::dbg::detail::TPrintf ("\n");
        va_end (vlist);
}

void nndbgDetailPutString (const char* text, int length)
{
        nn::dbg::detail::PutString (text, length);
}

void nndbgDetailVPrintf (const char* fmt, va_list arg)
{
        nn::dbg::detail::VPrintf (fmt, arg);
}

void nndbgDetailTVPrintf (const char* fmt, va_list arg)
{
        nn::dbg::detail::TVPrintf (fmt, arg);
}

void nndbgDetailPrintf (const char* fmt, ...)
{
        va_list vlist;
        va_start (vlist, fmt);
        nn::dbg::detail::Printf (fmt, vlist);
        va_end (vlist);
}

void nndbgDetailTPrintf (const char* fmt, ...)
{
        va_list vlist;
        va_start (vlist, fmt);
        nn::dbg::detail::TPrintf (fmt, vlist);
        va_end (vlist);
}
}
