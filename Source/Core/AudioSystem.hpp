
#pragma once

#ifndef _AUDIO_SYSTEM_HPP_
#define _AUDIO_SYSTEM_HPP_

#include "System.hpp"

class AudioSystem final : public System
{
public:
    virtual ~AudioSystem() = default;

    bool Initialize() override;
    void Update() override;
    void Destroy() override;

private:

};

#endif //_AUDIO_SYSTEM_HPP_