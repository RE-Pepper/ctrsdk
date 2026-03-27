#pragma once

namespace nn {
namespace ac {
namespace CTR {

struct Ssid
{
        size_t m_length;
        bit8   m_ssid[32];
        char8  m_ssidString[128];

        Ssid() {}
        ~Ssid() {}
}
} // namespace CTR
} // namespace ac
} // namespace nn
