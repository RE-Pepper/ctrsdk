#pragma once

namespace nn {
namespace os {

class ThreadLocalStorage
{
private:
        s32 m_Index;

public:
        ThreadLocalStorage();
        ~ThreadLocalStorage();

        uptr GetValue() const;
        void SetValue(uptr);

        static void ClearAllSlots();
};

static_assert_(sizeof(ThreadLocalStorage) == 0x4);

} // namespace os
} // namespace nn
