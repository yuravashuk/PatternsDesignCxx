
#pragma once

#ifndef _SYSTEM_HPP_
#define _SYSTEM_HPP_

class System
{
public:
    virtual ~System() = default;

    virtual bool Initialize() = 0;
    virtual void Update() = 0;
    virtual void Destroy() = 0;
};

#endif //_SYSTEM_HPP_