
#pragma once

#ifndef _ENEMY_AI_COMPONENT_HPP_
#define _ENEMY_AI_COMPONENT_HPP_

#include "AIComponent.hpp"
#include "../Core/StateMachine.hpp"

struct PlayerData
{
	float X = 40.0f;
	float Y = 40.0f;
};

enum StateTag : uint32_t
{
	ATTACK_TAG = 0,
	CHASE_TAG = 1,
    IDLE_TAG,
};

class EnemyAIComponent : public AIComponent
{
public:
    EnemyAIComponent();
    virtual ~EnemyAIComponent() = default;

    /* Life-Cycle Methods */

    void Initialize() override;

    void Update() override;

    void Destroy() override;

private:
    StateMachineDelegate *mIdleState;
    StateMachineDelegate *mAttackState;
    StateMachineDelegate *mChaseState;
};


#endif //_ENEMY_AI_COMPONENT_HPP_