
#include "AIComponent.hpp"

#include <iostream>

AIComponent::AIComponent()
    : mStateMachine(nullptr)
{ }

void AIComponent::Initialize() 
{
    if (mStateMachine == nullptr)
    {
        mStateMachine = new StateMachine();
    }
}

void AIComponent::Update()
{
    std::cout << "Update AIComponent\n";
}

void AIComponent::Destroy() 
{
    if (mStateMachine)
    {
        delete mStateMachine;
        mStateMachine = nullptr;
    }
}