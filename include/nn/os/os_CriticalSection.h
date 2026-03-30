#pragma once

#include <nn/util/util_NonCopyable.h>

namespace nn {
namespace os {

struct CriticalSection : nn::util::ADLFireWall::NonCopyable<HandleObject>
{
private:
        SimpleLock m_Lock;
        uptr       m_ThreadUniqueValue;
        s32        m_LockCount;

public:
};

struct ScopedLock
{
private:
        CriticalSection& m_Reference;

public:
        ScopedLock (CriticalSection& section);
};

} // namespace os
} // namespace nn

