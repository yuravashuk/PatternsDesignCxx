
#pragma once

#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

class Component
{
public:
    Component() = default;
    virtual ~Component() = default;

    /* Life-Cycle Methods */

    virtual void Initialize() = 0;

    virtual void Update() = 0;

    virtual void Destroy() = 0;
};

#endif //_COMPONENT_HPP_