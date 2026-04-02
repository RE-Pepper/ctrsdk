#pragma once

namespace nn {
namespace codec {
namespace CTR {

enum IirFilterTargetEQ // 64
{
        HP_32KHZ = 0,
        HP_48KHZ = 1,
        SP_32KHZ = 2,
        SP_48KHZ = 3
};

typedef struct
{
        u16 n0;
        u16 n1;
        u16 d1;
} IirFilterParamHalf; // 185
static_assert_ (sizeof (IirFilterParamHalf) == 0x6);

typedef struct
{
        u16 n0;
        u16 n1;
        u16 n2;
        u16 d1;
        u16 d2;
} IirFilterParamBiquad; // 194
static_assert_ (sizeof (IirFilterParamBiquad) == 0xA);

typedef struct
{
        IirFilterParamHalf   half;
        IirFilterParamBiquad biquadA;
        IirFilterParamBiquad biquadB;
        IirFilterParamBiquad biquadC;
        IirFilterParamBiquad biquadD;
        IirFilterParamBiquad biquadE;
} IirFilterParam; // 204
static_assert_ (sizeof (IirFilterParam) == 0x38);

typedef struct
{
        IirFilterParamBiquad biquadA;
        IirFilterParamBiquad biquadB;
        IirFilterParamBiquad biquadC;
} IirFilterParamEQ; // 220
static_assert_ (sizeof (IirFilterParamEQ) == 0x1E);

} // namespace CTR
} // namespace codec
} // namespace nn
