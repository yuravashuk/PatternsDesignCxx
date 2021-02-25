
#include "Actor.hpp"
#include "Utils.hpp"

Actor::Actor(uint32_t inID)
    : mID(inID)
{ }

/* Actor Life-Cycle Methods */

void Actor::Initialize( ) 
{ 
    for (auto component : mComponents)
    {
        component->Initialize();
    }
}

void Actor::Update( )
{
    for (auto component : mComponents)
    {
        component->Update();
    }
}

void Actor::Destroy()
{
    for (auto component : mComponents)
    {
        component->Destroy();

        Utils::SafeRelease(component);
    }

    mComponents.clear();
}

uint32_t Actor::GetID() const 
{ 
    return mID; 
}

/* Component Managment */

void Actor::AddComponent( Component* inComponent )
{
    if (inComponent)
    {
        mComponents.push_back( inComponent );
    }
}

void Actor::RemoveComponent( Component* inComponent )
{
    if (inComponent)
    {
        // 
    }
}