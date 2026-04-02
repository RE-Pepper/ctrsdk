#pragma once

#include <cwchar>
#include <nn/fslow/CTR/fs_PathNamesForSystem.h>

namespace nn {
namespace fslow {

template <class T, typename V>
class LowPath
{
private:
        bit32       m_PathType; // todo: possible enum?
        const void* m_Data;
        size_t      m_BinarySize;

public:
        LowPath ()
        {
                this->m_PathType   = 4;
                this->m_Data       = &m_Data;
                this->m_BinarySize = 1;
        }
        LowPath (const wchar_t* path)
        {
                this->m_PathType   = 4;
                this->m_Data       = path;
                this->m_BinarySize = 2 * (wcslen (path) + 1);
        }

        const wchar_t* GetWStringRaw ()
        {
                if (GetPathType () == 4) {
                        return (wchar_t*)this->m_Data;
                }
                return NULL;
        }
        bit32       GetPathType () { return this->m_PathType; }
        const void* GetDataBuffer () { return this->m_Data; }
        size_t      GetDataSize () { return this->m_BinarySize; }

        static LowPath Make (const T* p)
        {
                LowPath ret;
                ret.SetBinary (p);
                return ret;
        }

        void SetBinary (const T* p)
        {
                this->m_PathType   = 2;
                this->m_Data       = p;
                this->m_BinarySize = sizeof (T);
        }
};

} // namespace fslow
} // namespace nn

