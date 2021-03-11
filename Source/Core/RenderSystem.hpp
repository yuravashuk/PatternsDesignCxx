
#pragma once

#ifndef _RENDER_SYSTEM_HPP_
#define _RENDER_SYSTEM_HPP_

#include "System.hpp"
#include "../Game/MeshComponent.hpp"

#include <vector>
#include <map>
#include <string>

struct MeshData
{
    std::string FileName;
    std::vector< std::string > Textures;
};

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

    // Flyweight
    bool LoadMesh( const std::string &inFileName, MeshData &outData )
    {
        auto founded = mMeshCache.find( inFileName );

        if (founded != std::end(mMeshCache))
        {
            outData = founded->second;
            return true;
        }

        // load model file
        // parse model file data
        
        MeshData data;
        data.FileName = inFileName;
        mMeshCache.insert( { inFileName, data } );

        return true;
    }

private:
    std::vector< MeshComponent* > mComponents;

    std::map< std::string, MeshData > mMeshCache;
};

#endif //_RENDER_SYSTEM_HPP_