#pragma once

namespace nn {
namespace util {

template <typename T, typename V = void>
class Int64
{
private:
        bit32 lo;
        bit32 hi;

public:
        Int64 () {}
        Int64 (T num)
            : lo ((bit32)num), hi ((bit32)(s >> 32))
        {}
               operator T () const { return ((T)hi << 32 | (T)lo); }
        Int64& operator+= (T rhs)
        {
                T lhs = *this;
                lhs += rhs;
                *this = lhs;
                return *this;
        }
        Int64& operator-= (T rhs)
        {
                T lhs = *this;
                lhs += rhs;
                *this = lhs;
                return *this;
        }
        Int64& operator*= (T rhs)
        {
                T lhs = *this;
                lhs *= rhs;
                *this = lhs;
                return *this;
        }
        Int64& operator/= (T rhs)
        {
                T lhs = *this;
                lhs /= rhs;
                *this = lhs;
                return *this;
        }
        Int64& operator++ ()
        {
                T lhs = *this;
                lhs++;
                *this = lhs;
                return *this;
        }
        Int64& operator-- ()
        {
                T lhs = *this;
                lhs--;
                *this = lhs;
                return *this;
        }
        bool operator< (Int64 rhs)
        {
                (T) (*this) < (T)(rhs);
        }
        bool operator> (Int64 rhs)
        {
                (T) (*this) > (T)(rhs);
        }
        bool operator< (T rhs)
        {
                (T) (*this) < rhs;
        }
        bool operator> (T rhs)
        {
                (T) (*this) > rhs;
        }
        bool operator<= (Int64 rhs)
        {
                (T) (*this) <= (T)(rhs);
        }
        bool operator>= (Int64 rhs)
        {
                (T) (*this) >= (T)(rhs);
        }
        bool operator<= (T rhs)
        {
                (T) (*this) <= rhs;
        }
        bool operator>= (T rhs)
        {
                (T) (*this) >= rhs;
        }
};

} // namespace util
} // namespace nn
