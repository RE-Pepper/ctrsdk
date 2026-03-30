#pragma once

#ifdef __cplusplus

namespace nn {
namespace dbg {
namespace detail {

void PutString (const char* text, int length);
void PutString (const char* text);
void VPrintf (const char* fmt, va_list arg);
void TVPrintf (const char* fmt, va_list arg);
void Printf (const char* fmt, ...);
void TPrintf (const char* fmt, ...);

} // namespace detail
} // namespace dbg
} // namespace nn

#else

extern "C" {

void nndbgPrintWarning_ (const char* filename, int lineno, const char* fmt, ...);
void nndbgTPrintWarning_ (const char* filename, int lineno, const char* fmt, ...);
void nndbgDetailPutString (const char* text, int length);
void nndbgDetailVPrintf (const char* fmt, va_list arg);
void nndbgDetailTVPrintf (const char* fmt, va_list arg);
void nndbgDetailPrintf (const char* fmt, ...);
void nndbgDetailTPrintf (const char* fmt, ...);
}

#endif
