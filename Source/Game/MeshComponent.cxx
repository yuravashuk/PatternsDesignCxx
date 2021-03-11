
#include "MeshComponent.hpp"
#include "../Core/Core.hpp"

#include <iostream>

void MeshComponent::Initialize()
{
    auto renderer = Core::Shared().GetRenderSystem();
    renderer->RegisterMeshComponent( this );
    MeshData data;

    if (!renderer->LoadMesh( mFileName, data ))
    {
        std::cerr << "Failed to load mesh!\n";
    }
}

void MeshComponent::Update()
{
    std::cout << "Actor mesh file name: " << mFileName << "\n";
}

void MeshComponent::Destroy()
{
    // unload 3d mesh from memory

    // unregister from rendering pipeline
    auto renderer = Core::Shared().GetRenderSystem();
    renderer->UnregisterMeshComponent( this );
}

void MeshComponent::SetMesh(const std::string &inFilename)
{
    mFileName = inFilename;
}

std::string MeshComponent::GetMesh() const 
{
    return mFileName;
}