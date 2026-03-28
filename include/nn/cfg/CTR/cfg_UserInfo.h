#pragma once

namespace nn {
namespace cfg {
namespace CTR {

struct UserName
{
        unsigned short userName[11];
        bool           isNgUserName;
};

struct Birthday
{
        s8 month;
        s8 day;
};

struct SimpleAddress
{
        u32 id;

        unsigned short countryName[64];
        unsigned short regionName[16];

        u16 latitude;
        u16 longitude;
};

} // namespace CTR
} // namespace cfg
} // namespace nn
