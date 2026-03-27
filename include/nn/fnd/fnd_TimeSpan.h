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

        TimeSpan(ZeroOnly zero = 0) :
            m_NanoSeconds((s64)zero)
        {}

public:
        // Creating
        static TimeSpan FromNanoSeconds(s64 nanoSeconds)
        {
                return TimeSpan((ZeroOnly)nanoSeconds);
        }
        static TimeSpan FromMicroSeconds(s64 microSeconds)
        {
                return FromNanoSeconds(microSeconds * 1000);
        }
        static TimeSpan FromMilliSeconds(s64 milliSeconds)
        {
                return FromNanoSeconds(milliSeconds * 1000000);
        }
        static TimeSpan FromSeconds(s64 seconds)
        {
                return FromNanoSeconds(seconds * 1000000000);
        }
        static TimeSpan FromMinutes(s64 minutes)
        {
                return FromNanoSeconds(minutes * 60000000000);
        }
        static TimeSpan FromHours(s64 hours)
        {
                return FromNanoSeconds(hours * 3600000000000);
        }

        // Getting/Converting
        s64 GetNanoSeconds() const
        {
                return m_NanoSeconds;
        }
        s64 GetMicroSeconds() const
        {
                return m_NanoSeconds / 1000;
        }
        s64 GetMilliSeconds() const
        {
                return m_NanoSeconds / 1000000;
        }
        s64 GetSeconds() const
        {
                return m_NanoSeconds / 1000000000;
        }
        s64 GetMinutes() const
        {
                return m_NanoSeconds / 60000000000;
        }
        s64 GetHours() const
        {
                return m_NanoSeconds / 3600000000000;
        }

        // Checking
        friend bool operator==(const TimeSpan& lhs, const TimeSpan& rhs)
        {
                return lhs.m_NanoSeconds == rhs.m_NanoSeconds;
        }
        friend bool operator!=(const TimeSpan& lhs, const TimeSpan& rhs)
        {
                return lhs.m_NanoSeconds != rhs.m_NanoSeconds;
        }
        friend bool operator<(const TimeSpan& lhs, const TimeSpan& rhs)
        {
                return lhs.m_NanoSeconds < rhs.m_NanoSeconds;
        }
        friend bool operator>(const TimeSpan& lhs, const TimeSpan& rhs)
        {
                return lhs.m_NanoSeconds > rhs.m_NanoSeconds;
        }
        friend bool operator<=(const TimeSpan& lhs, const TimeSpan& rhs)
        {
                return lhs.m_NanoSeconds <= rhs.m_NanoSeconds;
        }
        friend bool operator>=(const TimeSpan& lhs, const TimeSpan& rhs)
        {
                return lhs.m_NanoSeconds >= rhs.m_NanoSeconds;
        }

        // Modifying
        TimeSpan& operator+=(const TimeSpan& rhs)
        {
                this->m_NanoSeconds += rhs.m_NanoSeconds;
                return *this;
        }
        TimeSpan& operator-=(const TimeSpan& rhs)
        {
                this->m_NanoSeconds += rhs.m_NanoSeconds;
                return *this;
        }
        TimeSpan& operator*=(const TimeSpan& rhs)
        {
                this->m_NanoSeconds *= rhs.m_NanoSeconds;
                return *this;
        }
        TimeSpan& operator/=(const TimeSpan& rhs)
        {
                this->m_NanoSeconds /= rhs.m_NanoSeconds;
                return *this;
        }

        friend TimeSpan operator+(const TimeSpan& lhs, const TimeSpan& rhs)
        {
                TimeSpan retval = FromNanoSeconds(lhs.m_NanoSeconds);
                retval.m_NanoSeconds += rhs.m_NanoSeconds;
                return retval;
        }
        friend TimeSpan operator-(const TimeSpan& lhs, const TimeSpan& rhs)
        {
                TimeSpan retval = FromNanoSeconds(lhs.m_NanoSeconds);
                retval.m_NanoSeconds -= rhs.m_NanoSeconds;
                return retval;
        }
};

} // namespace fnd
} // namespace nn
