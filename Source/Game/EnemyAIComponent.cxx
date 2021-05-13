
#include <iostream>

#include "EnemyAIComponent.hpp"


PlayerData g_PlayerData;

// Attack Player State Class
class AttackState : public StateMachineDelegate
{
public:
	virtual ~AttackState() = default;

    void OnBind(StateMachine *inStateMachine) override 
	{
		mStateMachine = inStateMachine;

		std::cout << "On Bind Attack State!\n"; 
	}

    void OnExecute() override 
	{ 
		std::cout << "On Execute Attack State!\n"; 

		float distance = 30.0f;

		if ((g_PlayerData.X <= distance) && (g_PlayerData.Y <= distance))
		{
			std::cout << "Yes we will attack the player!!\n";
		} 
		else 
		{
			mStateMachine->Execute( StateTag::CHASE_TAG );
		}
	}

    void OnDestroy() override { std::cout << "On Destroy Attack State!\n"; }
private:
	StateMachine *mStateMachine;
};

// Chase Player State Class
class ChaseState : public StateMachineDelegate
{
public:
	virtual ~ChaseState() = default;

    void OnBind(StateMachine *inStateMachine) override 
	{ 
		mStateMachine = inStateMachine;
		std::cout << "On Bind Chase State!\n"; 
	}

    void OnExecute() override 
	{ 
		std::cout << "On Execute Chase State!\n"; 

		float distance = 30.0f;

		if ((g_PlayerData.X >= distance) || (g_PlayerData.Y >= distance)) 
		{
			std::cout << "Okay, we are chasing the player!\n";
			g_PlayerData.X = g_PlayerData.Y = 10.0f;
		}
		else 
		{
			mStateMachine->Execute( StateTag::ATTACK_TAG );
		}
	}

    void OnDestroy() override { std::cout << "On Destroy Chase State!\n"; }
private:
	StateMachine *mStateMachine;
};

// Idle State Class
class IdleState : public StateMachineDelegate
{
public:
	virtual ~IdleState() = default;

    void OnBind(StateMachine *inStateMachine) override 
	{ 
		mStateMachine = inStateMachine;
		std::cout << "On Bind Idle State!\n"; 
	}

    void OnExecute() override 
	{ 
		std::cout << "On Execute Idle State!\n"; 
	}

    void OnDestroy() override 
    { std::cout << "On Destroy Chase State!\n"; }
private:
	StateMachine *mStateMachine;
};



EnemyAIComponent::EnemyAIComponent()
    : AIComponent()
    , mIdleState(nullptr)
    , mAttackState(nullptr)
    , mChaseState(nullptr)
{ }

void EnemyAIComponent::Initialize() 
{
    AIComponent::Initialize();

    mIdleState = new IdleState();
    mAttackState = new AttackState();
	mChaseState = new ChaseState();
	
    mStateMachine->AddState( StateTag::IDLE_TAG, mIdleState );
	mStateMachine->AddState( StateTag::ATTACK_TAG, mAttackState );
	mStateMachine->AddState( StateTag::CHASE_TAG, mChaseState );
}

void EnemyAIComponent::Update()
{
    AIComponent::Update();

    std::cout << "Update Enemy AIComponent\n";

    
}

void EnemyAIComponent::Destroy() 
{
    if (mIdleState)
    {
        delete mIdleState;
        mIdleState = nullptr;
    }

    if (mAttackState)
    {
        delete mAttackState;
        mAttackState = nullptr;
    }

    if (mChaseState)
    {
        delete mChaseState;
        mChaseState = nullptr;
    }
    
    AIComponent::Destroy();
}