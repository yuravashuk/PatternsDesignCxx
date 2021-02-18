
#include <iostream>

#include "StatComponent.hpp"

StatComponent::StatComponent( const std::string &inName, int inLevel )
    : mName(inName)
    , mLevel(inLevel)
{ 
    memset( &mStat, 0, sizeof(StatComponentData) );
}

// error: an initializer for a delegating constructor must appear alone
StatComponent::StatComponent( const std::string &inName, int inLevel, const StatComponentData &inData )
    : StatComponent(inName, inLevel)
{ 
    mStat = inData;
}

/* Life-Cycle Methods */

void StatComponent::Initialize()
{
    std::cout << "Initialize stat component\n";
    std::cout << "Health: " << mStat.Health << "\n";
    std::cout << "Speed: " << mStat.Speed << "\n";
    std::cout << "--------------------------\n";
}

void StatComponent::Update() 
{
    std::cout << "Update stat component\n";
}

void StatComponent::Destroy() 
{
    std::cout << "Destroy stat component\n";
}

void StatComponent::SetStatData( const StatComponentData &inData ) 
{
     mStat = inData; 
}

StatComponentData& StatComponent::GetStatData() 
{
    return mStat; 
}

std::string StatComponent::GetName() const 
{
    return mName; 
}

int StatComponent::GetLevel() const 
{ 
    return mLevel; 
}