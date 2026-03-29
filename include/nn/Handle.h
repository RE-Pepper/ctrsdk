#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct nnHandle
{
        bit32 value;
} nnHandle;

namespace {
const nnHandle INVALID_HANDLE_VALUE = { 0x0 };
}

#ifdef __cplusplus
}
#endif

namespace nn {

class Handle
{
protected:
        bit32 m_Handle;

public:
        Handle()
            : m_Handle(0)
        {}
        Handle(nnHandle handle)
            : m_Handle(handle.value)
        {}
        Handle(bit32 value)
            : m_Handle(value)
        {}

        bool IsValid() const
        {
                return this->m_Handle != 0;
        }

        bit32 GetPrintableBits() const
        {
                return this->m_Handle;
        }

        bool operator==(const Handle& rhs) const { return this->m_Handle == rhs.m_Handle; }
        bool operator!=(const Handle& rhs) const { return this->m_Handle != rhs.m_Handle; }
             operator nnHandle() const { return (nnHandle){ this->m_Handle }; }
};

} // namespace nn

