#pragma

#ifdef __cplusplus

namespace nn {
namespace nstd {

s32 TVSNPrintf (char* dst, size_t len, const char* fmt, va_list vlist);
s32 TSNPrintf (char* dst, size_t len, const char* fmt, ...);
s32 TSPrintf (char* dst, const char* fmt, ...);

} // namespace nstd
} // namespace nn

#else

extern "C" {

s32 nnnstdTVSNPrintf (char* dst, size_t len, const char* fmt, va_list vlist);
s32 nnnstdTSNPrintf (char* dst, size_t len, const char* fmt, ...);
s32 nnnstdTSPrintf (char* dst, const char* fmt, ...);
}

#endif
