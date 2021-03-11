
#pragma once

#ifndef _WORLD_HPP_
#define _WORLD_HPP_

#include <vector>
#include <string>

#include "Actor.hpp"

class World final 
{
public:
    World() = default;
    ~World() = default;

    bool Load(const std::string &inFileName);

    void Initialize();

    void Destroy();

    void AddActor(Actor* inActor);

    void RemoveActor(Actor* inActor);

    void RemoveActor(const std::string &inActorName);

    Actor* FindActor(const std::string &inActorName);

    std::vector< Actor* >& GetAllActors();

private:
    std::vector< Actor* > mActors;
};

#endif //_WORLD_HPP_