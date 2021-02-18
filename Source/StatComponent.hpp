
#pragma once

#ifndef _STAT_COMPONENT_HPP_
#define _STAT_COMPONENT_HPP_

#include <string>

#include "Component.hpp"

struct StatComponentData
{
    int Strengh;
    int Agility;
    int Intelligence;

    int Health;
    int Attack;
    int Speed;
    int Stamina;
    int Mana;
};

class StatComponent : public Component
{
public:
    StatComponent( const std::string &inName, int inLevel )
        : mName(inName)
        , mLevel(inLevel)
    { 
        memset( &mStat, 0, sizeof(StatComponentData) );
    }

    // error: an initializer for a delegating constructor must appear alone
    StatComponent( const std::string &inName, int inLevel, const StatComponentData &inData )
        : StatComponent(inName, inLevel)
    { 
        mStat = inData;
    }

    /* Life-Cycle Methods */

    void Initialize() override
    {
        std::cout << "Initialize stat component\n";
        std::cout << "Health: " << mStat.Health << "\n";
        std::cout << "Speed: " << mStat.Speed << "\n";
        std::cout << "--------------------------\n";
    }

    void Update() override 
    {
        std::cout << "Update stat component\n";
    }

    void Destroy() override 
    {
        std::cout << "Destroy stat component\n";
    }

    void SetStatData( const StatComponentData &inData ) { mStat = inData; }
    StatComponentData& GetStatData() { return mStat; }

    // get/set 
    std::string GetName() const { return mName; }
    int GetLevel() const { return mLevel; }

private:
    std::string mName;
    StatComponentData mStat;
    int mLevel;
};

enum CharacterType : uint8_t
{
    Warrior, Wizard, Enemy
};

class CharacterStatFactory final 
{
public:
    StatComponentData CreateStatData( CharacterType inType )
    {
        switch (inType)
        {
        case CharacterType::Warrior:
            return GetWarriorData();

        case CharacterType::Wizard:
            return GetWizardData();

        case CharacterType::Enemy:
            return GetEnemyData();

        default:
            return StatComponentData();
        }
    }

    static CharacterStatFactory& GetShared() 
    {
        static CharacterStatFactory instance;
        return instance;
    }

private:
    CharacterStatFactory() = default;
    CharacterStatFactory(const CharacterStatFactory&) = default;
    CharacterStatFactory(CharacterStatFactory&&) = default;

    CharacterStatFactory& operator=(const CharacterStatFactory&) = default;
    CharacterStatFactory& operator=(CharacterStatFactory&&) = default;
 
private:
    StatComponentData GetWizardData()
    {
        StatComponentData data;
	    data.Health = 50;
	    data.Agility = 60;
	    data.Intelligence = 100;
        data.Speed = 80;
        return data;
    }

    StatComponentData GetWarriorData()
    {
        StatComponentData data;
	    data.Health = 100;
	    data.Agility = 4;
	    data.Intelligence = 50;
        data.Speed = 60;
        return data;
    }

    StatComponentData GetEnemyData()
    {
        StatComponentData data;
	    data.Health = 80;
	    data.Agility = 54;
	    data.Intelligence = 20;
        data.Speed = 40;
        return data;
    }
};

#endif //_STAT_COMPONENT_HPP_