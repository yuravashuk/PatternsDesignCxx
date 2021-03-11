
#include "World.hpp"

bool World::Load(const std::string &inFileName)
{
    // load files (JSON, TXT, Binary etc.)
    // parse file
    // create actors and append them to mActors variable

    return true;
}

void World::Initialize()
{
    for (auto actor : mActors)
    {
        actor->Initialize();
    }
}

void World::Destroy()
{
    for (auto actor : mActors)
    {
        actor->Destroy();
    }

    mActors.clear();
}

void World::AddActor(Actor* inActor)
{
    mActors.push_back( inActor );
}

void World::RemoveActor(Actor* inActor)
{
    auto itr = std::find( std::begin(mActors), std::end(mActors), inActor );
    mActors.erase( itr );
}

void World::RemoveActor(const std::string &inActorName)
{

}

Actor* World::FindActor(const std::string &inActorName)
{
    return nullptr;
}

std::vector< Actor* >& World::GetAllActors()
{
    return mActors;
}