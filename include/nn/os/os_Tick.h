#pragma once

#include <nn/fnd/fnd_TimeSpan.h>

#include "nn/svc/svc_Stub.h"

namespace nn {
namespace os {

class Tick
{
private:
        s64 m_Tick;

public:
        Tick (s64 tick) : m_Tick (tick) {} // 51
        Tick (fnd::TimeSpan span);         // 109

        operator s64 () { return m_Tick; } // 63
        operator fnd::TimeSpan ();         // 113

        fnd::TimeSpan ToTimeSpan (); // 118

        static Tick GetSystemCurrent (); // 104

        Tick& operator-= (Tick rhs) { this->m_Tick -= rhs.m_Tick; } // 89
        Tick  operator- (Tick rhs) {}                               // 90
};

Tick Tick::GetSystemCurrent () // 104
{
        return Tick (svc::GetSystemTick ());
}

Tick::Tick (fnd::TimeSpan span) // 109
{
        // TODO
}
Tick::operator fnd::TimeSpan () // 113
{
        // TODO
}

fnd::TimeSpan Tick::ToTimeSpan () // 118
{
        // TODO
}

} // namespace os
} // namespace nn
