#pragma once

#include <nn/Handle.h>
#include <nn/err/CTR/err_FatalErrInfo.h>

namespace nn {
namespace err {
namespace CTR {

class FatalErr
{
private:
        Handle m_Session;

public:
        FatalErr(Handle session) : m_Session(session) {}

        Result Throw(const FatalErrInfo& info);
        Result SetUserString(const s8*, size_t);
};

} // namespace CTR
} // namespace err
} // namespace nn
