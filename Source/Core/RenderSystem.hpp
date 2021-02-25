
#pragma once

#ifndef _RENDER_SYSTEM_HPP_
#define _RENDER_SYSTEM_HPP_

#include "System.hpp"
#include "../Game/MeshComponent.hpp"

#include <vector>

class RenderSystem final : public System 
{
public:
    virtual ~RenderSystem() = default;

    bool Initialize() override;
    void Update() override;
    void Destroy() override;

    void Render();
    
    void RegisterMeshComponent( MeshComponent* inComponent );
    void UnregisterMeshComponent( MeshComponent* inComponent ) { }

private:
    std::vector< MeshComponent* > mComponents;
};

#endif //_RENDER_SYSTEM_HPP_