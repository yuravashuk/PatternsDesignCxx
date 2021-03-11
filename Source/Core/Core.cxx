
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

    // Create the Game World
    mWorld = new World();

    if (!mWorld->Load("simple_map.json"))
    {
        std::cerr << "Failed to load default world map!\n";
        return false;
    }

    mWorld->Initialize();

    return true;
}

void Core::DestroySystems()
{
    mRenderer->Destroy();
    mAudio->Destroy();
    mWorld->Destroy();

    Utils::SafeRelease( mRenderer, nullptr);
    Utils::SafeRelease( mAudio, nullptr );
    Utils::SafeRelease( mWorld, nullptr );
}

void Core::RunGameLoop()
{
   // while (!mQuit)
    for (int i = 0; i < 2; i++)
    {
        // receive input 

		// update all actors
		for (auto actor : mWorld->GetAllActors())
		{
			actor->Update();
			std::cout << "----------\n";
		}

		// render all actors
		mRenderer->Render();

		// render audio
		// update AI
    }
}

void Core::Quit()
{
    mQuit = true;
}

RenderSystem* Core::GetRenderSystem()
{
    return mRenderer;
}

AudioSystem* Core::GetAudioSystem()
{
    return mAudio;
}

World* Core::GetWorld()
{
    return mWorld;
}