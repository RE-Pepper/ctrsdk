#include <string>

RP_SHUTUP

namespace {
template <typename Type>
struct TVSNPrintfImpl
{
        typedef typename Type::char_type CharT;

        struct dst_string
        {
                size_t len;  // remaining capacity
                CharT* cur;  // current write cursor
                CharT* base; // start of destination
        };

        static void string_put_char (dst_string* p, CharT c)
        {
                if (p->len) {
                        *p->cur = c;
                        --p->len;
                }
                ++p->cur;
        }
        static void string_fill_char (dst_string* p, CharT c, int n)
        {
                if (n > 0) {
                        size_t len;
                        size_t i;

                        len = p->len;
                        if (p->len > n) {
                                len = n;
                        }
                        for (i = 0; i < len; ++i) {
                                p->cur[i] = c;
                        }
                        p->len -= len;
                        p->cur += n;
                }
        }
        static void string_put_string (dst_string* p, const CharT* s, int n)
        {
                if (n > 0) {
                        size_t len;
                        size_t i;

                        len = p->len;
                        if (p->len > n) {
                                len = n;
                        }
                        for (i = 0; i < len; ++i) {
                                p->cur[i] = s[i];
                        }
                        p->len -= len;
                        p->cur += n;
                }
        }

        // Observed function with locals:
        //   buf[24], n_buf, prefix[2], s, str,
        //   flag, width, precision, radix, hex_char, p_start,
        //   c, pad, n_buf2, p_buf, n_pad,
        //   plus nested integer temporaries: val (u64), d (int), v (u32), r (u64)
        static s32 TVSNPrintf (char* dst, size_t len, const CharT* fmt, va_list vlist)
        {
                // This is the main formatter body inferred from the debug info.
                // The DWARF shows a classic printf-style formatter:
                //   - parses flags / width / precision / radix
                //   - uses a small local conversion buffer buf[24]
                //   - formats signed/unsigned values via u32/u64 temporaries
                //   - handles padding via pad / n_pad
                //   - consumes strings through p_buf / s
                //   - writes into dst_string str

                dst_string str NN_UNUSED;
                str.len  = len;
                str.cur  = dst;
                str.base = dst;

                // Body not fully recoverable from the DWARF dump alone.
                // The locals strongly indicate standard printf semantics:
                //   %d/%i, %u, %x/%X, %o, %s, %c, width, precision, zero/space padding,
                //   sign handling, and alternate-prefix handling.
                //
                // The function returns the number of characters written, or similar s32.
                //
                // At the end, the destination is NUL-terminated if space remains.

                return 0;
        }
};
} // namespace

namespace nn {
namespace nstd {

s32 TVSNPrintf (char* dst, size_t len, const char* fmt, va_list vlist)
{
        return TVSNPrintfImpl<std::char_traits<char> >::TVSNPrintf (dst, len, fmt, vlist);
}

s32 TSNPrintf (char* dst, size_t len, const char* fmt, ...)
{
        va_list vlist;
        s32     ret;

        va_start (vlist, fmt);
        ret = TVSNPrintf (dst, len, fmt, vlist);
        va_end (vlist);

        return ret;
}

s32 TSPrintf (char* dst, const char* fmt, ...)
{
        va_list vlist;
        s32     ret;

        va_start (vlist, fmt);
        ret = TVSNPrintf (dst, 0x7FFFFFFF, fmt, vlist);
        va_end (vlist);

        return ret;
}

} // namespace nstd
} // namespace nn

extern "C" {

s32 nnnstdTVSNPrintf (char* dst, size_t len, const char* fmt, va_list vlist)
{
        return nn::nstd::TVSNPrintf (dst, len, fmt, vlist);
}

s32 nnnstdTSNPrintf (char* dst, size_t len, const char* fmt, ...)
{
        va_list vlist;
        s32     ret;

        va_start (vlist, fmt);
        ret = nn::nstd::TSNPrintf (dst, len, fmt, vlist);
        va_end (vlist);

        return ret;
}

s32 nnnstdTSPrintf (char* dst, const char* fmt, ...)
{
        va_list vlist;
        s32     ret;

        va_start (vlist, fmt);
        ret = nn::nstd::TSPrintf (dst, fmt, vlist);
        va_end (vlist);

        return ret;
}
}
