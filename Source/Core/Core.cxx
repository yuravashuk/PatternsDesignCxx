
#include "Core.hpp"
#include "Utils.hpp"

bool Core::InitializeSystems()
{
    // Initialize Render System
    mRenderer = new RenderSystem();
    
    if (!mRenderer->Initialize())
    {
        std::cerr << "Failed to initialize Rendering System!\n";
        return false;
    }

    // Initialize Audio System
    mAudio = new AudioSystem();
    
    if (!mAudio->Initialize())
    {
        std::cerr << "Failed to initialize Audio System!\n";
        return false;
    }

    return true;
}

void Core::DestroySystems()
{
    mRenderer->Destroy();
    mAudio->Destroy();

    Utils::SafeRelease( mRenderer, nullptr);
    Utils::SafeRelease( mAudio, nullptr );
}

RenderSystem* Core::GetRenderSystem()
{
    return mRenderer;
}

AudioSystem* Core::GetAudioSystem()
{
    return mAudio;
}