#pragma once

namespace nn {
namespace util {

template <typename T, typename V = void>
class SizedEnum
{
private:
        T m_EnumValue;

public:
        SizedEnum () {}
        SizedEnum (T e) : m_EnumValue (e) {}
        SizedEnum (V e) : m_EnumValue (e) {}

        T    Get () const { return this->m_EnumValue; }
        void Set (T e) const { this->m_EnumValue = e; }

        operator T () { return Get (); }
};

template <typename V>
struct SizedEnum1 : public SizedEnum<bit8, V>
{
        SizedEnum1 () : SizedEnum<bit8, V> () {}
        SizedEnum1 (V e) : SizedEnum<bit8, V> (e) {}
};
template <typename V>
struct SizedEnum2 : public SizedEnum<bit16, V>
{
        SizedEnum2 () : SizedEnum<bit16, V> () {}
        SizedEnum2 (V e) : SizedEnum<bit16, V> (e) {}
};
template <typename V>
struct SizedEnum4 : public SizedEnum<bit32, V>
{
        SizedEnum4 () : SizedEnum<bit32, V> () {}
        SizedEnum4 (V e) : SizedEnum<bit32, V> (e) {}
};

} // namespace util
} // namespace nn
