
#pragma once

#ifndef _STAT_FACTORY_HPP_
#define _STAT_FACTORY_HPP_

#include "StatComponent.hpp"
#include "GameTypes.hpp"

class StatFactory final 
{
public:
    static StatFactory& GetShared()
    {
        static StatFactory instance;
        return instance;
    }

    StatComponentData CreateStatData( CharacterType inType );

private:
    StatFactory() = default;
    StatFactory(const StatFactory&) = default;
    StatFactory(StatFactory&&) = default;

    StatFactory& operator=(const StatFactory&) = default;
    StatFactory& operator=(StatFactory&&) = default;
 
private:
    StatComponentData GetWizardData();
    StatComponentData GetWarriorData();
    StatComponentData GetEnemyData();
};

#endif //_STAT_FACTORY_HPP_