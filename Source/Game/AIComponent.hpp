
#pragma once

#ifndef _AI_COMPONENT_HPP_
#define _AI_COMPONENT_HPP_

#include "../Core/Component.hpp"
#include "../Core/StateMachine.hpp"

class AIComponent : public Component
{
public:
    AIComponent();
    virtual ~AIComponent() = default;

    /* Life-Cycle Methods */

    void Initialize() override;

    void Update() override;

    void Destroy() override;

protected:
    StateMachine* mStateMachine;

};


#endif // _AI_COMPONENT_HPP_