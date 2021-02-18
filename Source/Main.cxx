
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>

// ECS
#include "Core/Actor.hpp"
#include "Core/Component.hpp"
#include "Core/System.hpp"

#include "Game/StatComponent.hpp"
#include "Game/StatFactory.hpp"

#ifdef _WIN32
#if defined(_DEBUG)
#include <crtdbg.h>
#endif //_DEBUG
#endif //_WIN32

// Safe Pointers !

template<typename T>
void SafeRelease(T* inResource)
{
	if (inResource)
	{
		delete inResource;
	}
}

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
	
	// Allocate 
	const auto warriorData = StatFactory::GetShared().CreateStatData(CharacterType::Warrior);
	const auto waizardData = StatFactory::GetShared().CreateStatData(CharacterType::Wizard);
	const auto enemyData = StatFactory::GetShared().CreateStatData(CharacterType::Enemy);

	Actor *warriorActor = new Actor(0);
	warriorActor->AddComponent( new StatComponent("Warrior", 1, warriorData ));

	Actor *wizardActor = new Actor(1);
	wizardActor->AddComponent( new StatComponent("Wizzard", 2, waizardData ));

	Actor *enemyActor = new Actor(2);
	enemyActor->AddComponent( new StatComponent("Enemy", 2, enemyData) );

	std::vector< Actor* > actors = { warriorActor, wizardActor, enemyActor };

	for (auto actor : actors)
	{
		actor->Initialize();
	}

	// Clear Resources
	SafeRelease( warriorActor );
	SafeRelease( wizardActor );

	return 0;
}