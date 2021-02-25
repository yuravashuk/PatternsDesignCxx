
#pragma once

#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include <functional>

namespace Utils
{

    template<typename T>
    void SafeRelease(T* inResource)
    {
        if (inResource)
        {
            delete inResource;
        }
    }

    template<typename T>
    void SafeRelease( T* &inResource, void* newValue )
    {
        if (inResource)
        {
            delete inResource;
            inResource = (T*)newValue;
        }
    }

} // namespace Utils

#endif //_UTILS_HPP_