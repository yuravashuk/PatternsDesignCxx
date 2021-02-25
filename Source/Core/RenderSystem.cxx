
#include "RenderSystem.hpp"
#include <iostream>

bool RenderSystem::Initialize() 
{ 
    return true; 
}

void RenderSystem::Update() 
{ 

}

void RenderSystem::Destroy()
{ 
    
}

void RenderSystem::Render()
{
    for (auto component : mComponents)
    {
        std::cout << "Render mesh with file name : " << component->GetMesh() << "\n";
    }
}

void RenderSystem::RegisterMeshComponent( MeshComponent* inComponent )
{
    if (inComponent != nullptr)
    {
        mComponents.push_back( inComponent );
    }
}