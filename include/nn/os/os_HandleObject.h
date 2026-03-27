#pragma once

#include <nn/Handle.h>
#include <nn/util/util_NonCopyable.h>

namespace nn {
namespace os {

class HandleObject : nn::util::ADLFireWall::NonCopyable<HandleObject>
{
protected:
        Handle m_Handle;

public:
        Handle GetHandle() const
        {
                return m_Handle;
        }
        bool IsValid() const
        {
                return m_Handle.IsValid();
        }

        HandleObject() :
            nn::util::ADLFireWall::NonCopyable<HandleObject>()
        {}

        ~HandleObject()
        {
                Close();
        }

        void SetHandle(Handle handle)
        {
        }
        void Close();
        void ClearHandle();
        void DetachHandle();
};

} // namespace os
} // namespace nn
