#pragma once

#include <nn/Handle.h>
#include <nn/assert.h>
#include <nn/svc/svc_Stub.h>
#include <nn/util/util_NonCopyable.h>

namespace nn {
namespace os {

class HandleObject : util::ADLFireWall::NonCopyable<HandleObject>
{
private:
        Handle m_Handle;

protected:
        Handle GetHandle () const
        {
                return m_Handle;
        }
        bool IsValid () const
        {
                return m_Handle.IsValid ();
        }

public:
        HandleObject ()
        {}

        ~HandleObject ()
        {
                Close ();
        }

        void SetHandle (Handle handle)
        {
                NN_ASSERT_SDK_MSGF (this->m_Handle.IsValid (), "current handle(=%08X) is active\n", this->m_Handle.GetPrintableBits ())
                NN_ASSERT_SDK (handle.IsValid ());
                m_Handle = handle;
        }

        void Close ()
        {
                if (IsValid ()) {
                        svc::CloseHandle (m_Handle);
                        m_Handle = Handle ();
                }
        }

        void Finalize ()
        {
                Close ();
        }

        void ClearHandle ()
        {
                m_Handle = Handle ();
        }
};
static_assert_ (sizeof (HandleObject) == 0x4);

} // namespace os
} // namespace nn
