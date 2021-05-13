
#pragma once

#ifndef _STATE_MACHINE_HPP_
#define _STATE_MACHINE_HPP_

#include <map>
#include <cinttypes>

// forward declaration
class StateMachine;

// Utility AI (Utility Theory)

/*
    currentPlayerHealth / maxPlayerHealth   -> 0.4  -> 0.4 / 0.7 -> 
    hangryValue / satisfiedValue            -> 0.7

    Task1 - Heal Player - Score: 0.6
    Task2 - Eat Something - Score: 0.5
*/

// FSM - Finite State Machine
/*
        (attack)
         /
        /  - if i see the player ?
   (idle)   
      \  \ - if i dont see the player?
       \  \
        \ (patrol)
*/

// Behaviour Tree
/*
        (root)
        /   \
       /     \ 
     (E1)    (E2)
*/

/*
    AI Blackboard

    Key: Value
    PlayerTarget -> PlayerActorPtr
    MyHealth -> 100.0f
    CanAttack? -> true

*/

struct StateTransition
{
    virtual bool CanTransit() = 0;
};

struct CanAttack : public StateTransition 
{
    bool CanTransit() override { return MyDistanceToPlayer <= 30; }
};

class StateMachineDelegate
{
public:
    virtual ~StateMachineDelegate() = default;

    virtual void OnBind( StateMachine* inStateMachine ) = 0;
    virtual void OnExecute() = 0;
    virtual void OnDestroy() = 0;

public:
    std::list< Transitions > Transitions;
    std::list< std::function<bool(StateMachine*)> > TransitionsFuncs = {
        std::bind([] (StateMachine* sm) { return 30 < 60; })
     };
};

class StateMachine 
{
public:
    StateMachine() = default;

    ~StateMachine()
    {
        Clear();
    }

    void AddState( uint32_t inStateTag,  StateMachineDelegate* inState )
    {
        mDelegates.insert( { inStateTag, inState } );

        inState->OnBind( this );
    }

    void Execute( uint32_t inStateTag )
    {
        auto founded = mDelegates.find( inStateTag );

        if ( founded != std::end( mDelegates ) )
        {
            founded->second->OnExecute();
        }
    }

    void Clear( )
    {
        for (auto [k, v] : mDelegates)
        {
            if (v)
            {
                v->OnDestroy();
            }
        }

        mDelegates.clear();
    }

private:
    std::map< uint32_t, StateMachineDelegate* > mDelegates;  
};

#endif //_STATE_MACHINE_HPP_