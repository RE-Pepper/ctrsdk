#pragma once

namespace nn {
namespace fnd {

class TimeSpan
{
protected:
        s64 m_NanoSeconds;
        typedef const struct ZeroOnlyTag
        {
        }* ZeroOnly;

        TimeSpan (ZeroOnly zero = 0) : m_NanoSeconds ((s64)zero)
        {}

public:
        // Creating
        static TimeSpan FromNanoSeconds (s64 nanoSeconds)
        {
                TimeSpan ret;
                ret.m_NanoSeconds = nanoSeconds;
                return ret;
        }
        static TimeSpan FromMicroSeconds (s64 microSeconds)
        {
                return FromNanoSeconds (microSeconds * 1000);
        }
        static TimeSpan FromMilliSeconds (s64 milliSeconds)
        {
                return FromNanoSeconds (milliSeconds * 1000 * 1000);
        }
        static TimeSpan FromSeconds (s64 seconds)
        {
                return FromNanoSeconds (seconds * 1000 * 1000 * 1000);
        }
        static TimeSpan FromMinutes (s64 minutes)
        {
                return FromNanoSeconds (minutes * 1000 * 1000 * 1000 * 60);
        }
        static TimeSpan FromHours (s64 hours)
        {
                return FromNanoSeconds (hours * 1000 * 1000 * 1000 * 60 * 60);
        }

        // Getting/Converting
        s64 GetNanoSeconds () const
        {
                return m_NanoSeconds;
        }
        s64 GetMicroSeconds () const
        {
                return m_NanoSeconds / 1000;
        }
        s64 GetMilliSeconds () const
        {
                return m_NanoSeconds / (1000 * 1000);
        }
        s64 GetSeconds () const
        {
                return m_NanoSeconds / (1000 * 1000 * 1000);
        }
        s64 GetMinutes () const
        {
                return m_NanoSeconds / (1000LL * 1000 * 1000 * 60);
        }
        s64 GetHours () const
        {
                return m_NanoSeconds / (1000LL * 1000 * 1000 * 60 * 60);
        }

        // Checking
        friend bool operator== (const TimeSpan& lhs, const TimeSpan& rhs)
        {
                return lhs.m_NanoSeconds == rhs.m_NanoSeconds;
        }
        friend bool operator!= (const TimeSpan& lhs, const TimeSpan& rhs)
        {
                return lhs.m_NanoSeconds != rhs.m_NanoSeconds;
        }
        friend bool operator< (const TimeSpan& lhs, const TimeSpan& rhs)
        {
                return lhs.m_NanoSeconds < rhs.m_NanoSeconds;
        }
        friend bool operator> (const TimeSpan& lhs, const TimeSpan& rhs)
        {
                return lhs.m_NanoSeconds > rhs.m_NanoSeconds;
        }
        friend bool operator<= (const TimeSpan& lhs, const TimeSpan& rhs)
        {
                return lhs.m_NanoSeconds <= rhs.m_NanoSeconds;
        }
        friend bool operator>= (const TimeSpan& lhs, const TimeSpan& rhs)
        {
                return lhs.m_NanoSeconds >= rhs.m_NanoSeconds;
        }

        // Modifying
        TimeSpan& operator+= (const TimeSpan& rhs)
        {
                this->m_NanoSeconds += rhs.m_NanoSeconds;
                return *this;
        }
        TimeSpan& operator-= (const TimeSpan& rhs)
        {
                this->m_NanoSeconds += rhs.m_NanoSeconds;
                return *this;
        }
        TimeSpan& operator*= (const TimeSpan& rhs)
        {
                this->m_NanoSeconds *= rhs.m_NanoSeconds;
                return *this;
        }
        TimeSpan& operator/= (const TimeSpan& rhs)
        {
                this->m_NanoSeconds /= rhs.m_NanoSeconds;
                return *this;
        }

        friend TimeSpan operator+ (const TimeSpan& lhs, const TimeSpan& rhs)
        {
                TimeSpan retval = FromNanoSeconds (lhs.m_NanoSeconds);
                retval.m_NanoSeconds += rhs.m_NanoSeconds;
                return retval;
        }
        friend TimeSpan operator- (const TimeSpan& lhs, const TimeSpan& rhs)
        {
                TimeSpan retval = FromNanoSeconds (lhs.m_NanoSeconds);
                retval.m_NanoSeconds -= rhs.m_NanoSeconds;
                return retval;
        }
};
static_assert_ (sizeof (TimeSpan) == 0x8);

} // namespace fnd
} // namespace nn
