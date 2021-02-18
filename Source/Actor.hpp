
#pragma once

#ifndef _ACTOR_HPP_
#define _ACTOR_HPP_

#include "Component.hpp"

#include <vector>

class Actor 
{
    using TComponents = std::vector< Component* >;
    
public:
    Actor(uint32_t inID)
        : mID(inID)
    { }

    /* Actor Life-Cycle Methods */

    void Initialize( ) 
    { 
        for (auto component : mComponents)
        {
            component->Initialize();
        }
    }

    void Update( )
    {
        for (auto component : mComponents)
        {
            component->Update();
        }
    }

    void Destroy()
    {
        for (auto component : mComponents)
        {
            component->Destroy();
        }
    }

    /* Common */
    
    uint32_t GetID() const { return mID; }

    /* Component Managment */

    void AddComponent( Component* inComponent )
    {
        if (inComponent)
        {
            mComponents.push_back( inComponent );
        }
    }

    void RemoveComponent( Component* inComponent )
    {
        if (inComponent)
        {
            // 
        }
    }

private:
    uint32_t mID;
    TComponents mComponents;
};

#endif //_ACTOR_HPP_