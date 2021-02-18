
#include "StatFactory.hpp"

StatComponentData StatFactory::CreateStatData( CharacterType inType )
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

StatComponentData StatFactory::GetWizardData()
{
    StatComponentData data;
    data.Health = 50;
    data.Agility = 60;
    data.Intelligence = 100;
    data.Speed = 80;
    return data;
}

StatComponentData StatFactory::GetWarriorData()
{
    StatComponentData data;
    data.Health = 100;
    data.Agility = 4;
    data.Intelligence = 50;
    data.Speed = 60;
    return data;
}

StatComponentData StatFactory::GetEnemyData()
{
    StatComponentData data;
    data.Health = 80;
    data.Agility = 54;
    data.Intelligence = 20;
    data.Speed = 40;
    return data;
}