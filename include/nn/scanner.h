#pragma once

namespace nn {
namespace ac {
namespace CTR {

enum PrivacyMode
{
        PRIVACY_MODE_NONE      = 0,
        PRIVACY_MODE_WEP       = 1,
        PRIVACY_MODE_WPA_TKIP  = 2,
        PRIVACY_MODE_WPA_AES   = 3,
        PRIVACY_MODE_WPA2_TKIP = 4,
        PRIVACY_MODE_WPA2_AES  = 5,
};

struct AccessPoint
{
        Ssid        ssid;
        Bssid       bssid;
        s16         rssi;
        u8          linkLevel;
        u8          channel;
        PrivacyMode privacyMode;
        PriavcyMode groupPrivacyMode;
        bool        hasNintendoIE;
};


} // namespace CTR
} // namespace ac
} // namespace nn
