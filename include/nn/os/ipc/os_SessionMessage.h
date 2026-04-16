#pragma once

#include <nn/Handle.h>
#include <nn/os/CTR/os_ThreadLocalRegion.h>
#include <string.h>

namespace nn {
namespace os {
namespace ipc {

bit32* GetMessageBuffer() // 33
{
        return CTR::GetThreadLocalRegion()->messageBuffer;
}
bit32* GetReceiveBuffer() // 37
{
        return CTR::GetThreadLocalRegion()->receiveBuffer;
}

struct MessageBuffer
{
private:
        bit32* m_p;

public:
        enum WordType
        {
                WORD_TYPE_HANDLE_COPY = 0,
                WORD_TYPE_HANDLE_MOVE = 1,
                WORD_TYPE_PROCESS_I   = 2
        };

        MessageBuffer(bit32* p) : m_p(p) {}
        MessageBuffer(s32 offset, bit32* p) {}

        void SetHeader(bit16 tag, s32 rawlen, s32 fmtlen, bit8 flags)
        {
                *m_p = MakeHeader(tag, rawlen, fmtlen, flags);
        }
        void SetRawArray(s32 offset, const void* p, size_t size)
        {
                memcpy(m_p + offset, p, size);
        }
        void SetSend(s32 offset, const void* p, size_t size)
        {
                *(m_p + offset)     = (size << 4) & 0xFFFFFFF0 | 0xA;
                *(m_p + offset + 1) = (bit32)p;
        }
        void SetReceive(s32 offset, const void* p, size_t size)
        {
                *(m_p + offset)     = (size << 4) & 0xFFFFFFF0 | 0xC;
                *(m_p + offset + 1) = (bit32)p;
        }
        void SetCopyHandleHeader(s32 offset, s32 num)
        {
                *(m_p + offset) = MakeSpecialWordHeader(WORD_TYPE_HANDLE_COPY, num - 1);
        }
        void SetHandle(s32 offset, Handle handle)
        {
                SetSpecialWord(m_p, offset, (bit32&)handle);
        }
        void SetProcessIdHeader(s32 offset)
        {
                *(m_p + offset) = MakeSpecialWordHeader(WORD_TYPE_PROCESS_I, 0);
        }
        void SetPointerHeader(s32 offset, s32 index, size_t size)
        {
                SetPointerHeader(m_p, offset, index, size);
        }
        void SetPointerHeaderForReceive(s32 offset, size_t size)
        {
                SetPointerHeader(m_p, offset, 0, size);
        }
        void SetPointer(s32 offset, const void* p)
        {
                SetPointer(m_p, offset, p);
        }

        Handle GetHandle(s32 offset) { return Handle(Get(offset)); }
        bit32  Get(s32 offset) { return m_p[offset]; }

        static bit32 MakeHeader(bit16 tag, s32 rawlen, s32 fmtlen, bit8 flags)
        {
                return (tag << 16) | ((flags & 0xF) << 12) | ((rawlen & 0x3F) << 6) | (fmtlen & 0x3F);
        }
        static bit32 MakeSpecialWordHeader(WordType type, s32 numData)
        {
                return (numData << 26) | (type << 4) & 0x30;
        }

        static void SetSpecialWord(bit32* pBase, s32 offset, bit32 value)
        {
                *(pBase + offset) = value;
        }
        static void SetPointerHeader(bit32* pBase, s32 offset, s32 index, size_t size)
        {
                *(pBase + offset) = ((size << 14) & 0xFFFFC000) | ((index << 10) & 0x3C00) | 2;
        }
        static void SetPointer(bit32* pBase, s32 offset, const void* p)
        {
                *(pBase + offset) = (bit32)p;
        }

        template <typename T>
        void SetRaw(s32 offset, const T& value)
        {
                *((T*)m_p + offset) = value;
        }

        template <typename T>
        const T& GetRaw(s32 offset)
        {
                return *(const T*)(m_p + offset);
        }

        template <typename T>
        void GetRawArray(s32 offset, T* p, size_t size)
        {
                return memcpy(p, m_p + offset, size);
        }
};

} // namespace ipc
} // namespace os
} // namespace nn
