#pragma once

namespace nn {
namespace ac {
namespace CTR {

struct Bssid
{
        bit8  mac[6];
        bit8  m_pad_[2];
        char8 m_macString[18];

        Bssid() {}
        ~Bssid() {}

        // Get() comes here
}

} // namespace CTR
} // namespace ac
} // namespace nn
