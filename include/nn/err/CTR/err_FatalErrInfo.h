#pragma once

#include <nn/Result.h>
#include <nn/os/ARM/os_ExceptionHandler.h>

namespace nn {
namespace err {
namespace CTR {

struct FatalErrInfo {
        bit8     type;
        u8       revisionHi;
        u16      revisionLo;
        nnResult result;
        uptr     pc;
        bit32    processId;
        bit64    titleId;
        bit64    appTitleId;

        union {
                struct
                {
                        u8               info[24];
                        os::ARM::ExceptionContext context;
                } exception;
                struct
                {
                        char array[96];
                        char message[96];
                } failure;
        } data;
};

} // namespace CTR
} // namespace err
} // namespace nn
