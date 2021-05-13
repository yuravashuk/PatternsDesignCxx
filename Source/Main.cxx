
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>

// ECS
#include "Core/Utils.hpp"
#include "Core/Actor.hpp"
#include "Core/Component.hpp"
#include "Core/System.hpp"
#include "Core/RenderSystem.hpp"
#include "Core/Core.hpp"
#include "Core/StateMachine.hpp"

#include "Game/StatComponent.hpp"
#include "Game/MeshComponent.hpp"
#include "Game/StatFactory.hpp"

#include "Core/World.hpp"

#ifdef _WIN32
#if defined(_DEBUG)
#include <crtdbg.h>
#endif //_DEBUG
#endif //_WIN32

struct PlayerData
{
	float X = 40.0f;
	float Y = 40.0f;
} g_PlayerData;

enum StateTag : uint32_t
{
	ATTACK_TAG = 0,
	CHASE_TAG = 1
};

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


// Entry point
int main(void)
{
#ifdef _WIN32
#if defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
#endif //_DEBUG
#endif //_WIN32

	// Initialize Core Systems and Actors
	if (!Core::Shared().InitializeSystems())
	{
		return -1;
	}

	// Allocate Actors
	const auto warriorData = StatFactory::GetShared().CreateStatData(CharacterType::Warrior);
	const auto waizardData = StatFactory::GetShared().CreateStatData(CharacterType::Wizard);
	const auto enemyData = StatFactory::GetShared().CreateStatData(CharacterType::Enemy);

	Actor *warriorActor = new Actor(0);
	warriorActor->AddComponent( new StatComponent("Warrior", 1, warriorData ));
	warriorActor->AddComponent( new MeshComponent("./Content/Models/Warrior3D.fbx") );

	Actor *wizardActor = new Actor(1);
	wizardActor->AddComponent( new StatComponent("Wizzard", 2, waizardData ));

	Actor *enemyActor = new Actor(2);
	enemyActor->AddComponent( new StatComponent("Enemy", 2, enemyData) );

	// Register new Scene Actors
	Core::Shared().GetWorld()->AddActor( warriorActor );
	Core::Shared().GetWorld()->AddActor( wizardActor );
	Core::Shared().GetWorld()->AddActor( enemyActor );

	// Start Game Loop
	Core::Shared().RunGameLoop();

	// Clear resources
	Core::Shared().DestroySystems();

	// Clear Resources
	Utils::SafeRelease( warriorActor );
	Utils::SafeRelease( enemyActor );
	Utils::SafeRelease( wizardActor );


	std::cout << "\n------------------------\n";
	std::cout << "State Machine Tests!\n";

	auto machine = new StateMachine();

	auto attackState = new AttackState();
	auto chaseState = new ChaseState();
	
	machine->AddState( StateTag::ATTACK_TAG, attackState );
	machine->AddState( StateTag::CHASE_TAG, chaseState );

	machine->Execute( StateTag::CHASE_TAG );
	machine->Execute( StateTag::CHASE_TAG );
	//machine->Execute( StateTag::ATTACK_TAG );

	delete machine;

	delete attackState;
	delete chaseState;

	return 0;
}