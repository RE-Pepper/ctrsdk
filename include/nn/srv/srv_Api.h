#pragma once

#include <nn/Handle.h>
#include <nn/Result.h>
#include <nn/fnd/fnd_LinkedList.h>

namespace nn {
namespace srv {

class NotificationHandler : public nn::fnd::IntrusiveLinkedList<NotificationHandler>::Item
{
        bit32 m_AttachedMessage;
};

Result Initialize ();
Result GetServiceHandle (Handle* out, const char* service, s32, u32);

} // namespace srv
} // namespace nn
