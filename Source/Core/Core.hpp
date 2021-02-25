
#pragma once

#ifndef _CORE_HPP_
#define _CORE_HPP_

#include <vector>
#include <iostream>

#include "RenderSystem.hpp"
#include "AudioSystem.hpp"

class Core final 
{
public:
    Core(const Core&) = delete;
    Core(Core&&) = delete;

    Core& operator=(const Core&) = delete;
    Core& operator=(Core&&) = delete;

    static Core& Shared()
    {
        static Core instance;
        return instance;
    }

    bool InitializeSystems();

    void DestroySystems();

    RenderSystem* GetRenderSystem();

    AudioSystem* GetAudioSystem();

private:
    Core() = default;

private:
    RenderSystem* mRenderer;
    AudioSystem* mAudio;
};

#endif //_CORE_HPP_