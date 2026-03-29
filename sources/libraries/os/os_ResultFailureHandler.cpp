#include <nn/Result.h>

void nnosGetProcessId(bit32* pOut) // 23
{
        // TODO
}

namespace {
void nnosResultFailureHandlerImplDefault(nnResult result, const char* filename, int lineno, const char* fmt, va_list vlist) // 60
{
        // TODO
}
void nnosResultTFailureHandlerImplDefault(nnResult result, const char* filename, int lineno, const char* fmt, ...) // 60
{
        // TODO
}

void nnosResultPanicHandlerImplDefault(nnResult result, const char* filename, int lineno, const char* fmt, va_list vlist) // 66
{
        bit32 processId;
        // TODO
}
void nnosResultTPanicHandlerImplDefault(nnResult result, const char* filename, int lineno, const char* fmt, ...) // 84
{
        bit32 processId;
        // TODO
}
} // namespace

int nnResultTFailureHandler(nnResult result, const char* filename, int lineno, const char* fmt, ...)
{
        va_list __va_list;
        return 0;
        // TODO
}
