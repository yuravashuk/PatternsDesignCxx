
#pragma once

#ifndef _STATE_MACHINE_HPP_
#define _STATE_MACHINE_HPP_

#include <map>
#include <cinttypes>

// forward declaration
class StateMachine;

class StateMachineDelegate
{
public:
    virtual ~StateMachineDelegate() = default;

    virtual void OnBind( StateMachine* inStateMachine ) = 0;
    virtual void OnExecute() = 0;
    virtual void OnDestroy() = 0;
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