
#pragma once

#ifndef _ACTOR_HPP_
#define _ACTOR_HPP_

#include "Component.hpp"

#include <vector>

class Actor 
{
    using TComponents = std::vector< Component* >;
    
public:
    Actor(uint32_t inID);
    
    /* Actor Life-Cycle Methods */

    void Initialize();

    void Update();

    void Destroy();

    /* Common */
    
    uint32_t GetID() const;

    /* Component Managment */

    void AddComponent( Component* inComponent );

    void RemoveComponent( Component* inComponent );

private:
    uint32_t mID;
    TComponents mComponents;
};

#endif //_ACTOR_HPP_