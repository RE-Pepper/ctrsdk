#pragma once

namespace nn {
namespace util {
namespace detail {
template <size_t Alignment>
struct AlignmentType;

// DW_AT_const_value = 8
template <>
struct AlignmentType<8>
{
        typedef u64 type;
};
// DW_AT_const_value = 4
template <>
struct AlignmentType<4>
{
        typedef u32 type;
};
// DW_AT_const_value = 2
template <>
struct AlignmentType<2>
{
        typedef u16 type;
};
// DW_AT_const_value = 1
template <>
struct AlignmentType<1>
{
        typedef u8 type;
};

} // namespace detail

template <size_t Size, size_t Alignment>
struct aligned_storage
{
private:
        union UnionType {
                char c[Size];

                // Uses the AlignmentType utility we defined previously
                // to force the union to align to the requested boundary.
                typename detail::AlignmentType<Alignment>::type a;
        };

public:
        typedef UnionType type;
};

template <bool Condition, typename T = void>
struct enable_if;

// It defines 'type' as the second template parameter.
template <typename T>
struct enable_if<true, T>
{
        typedef T type;
};

} // namespace util
} // namespace nn
