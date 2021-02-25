
#pragma once

#ifndef _MESH_COMPONENT_HPP_
#define _MESH_COMPONENT_HPP_

#include <string>
#include "../Core/Component.hpp"

class MeshComponent : public Component 
{
public:
    MeshComponent(const std::string &inFileName)
        : mFileName(inFileName)
    { }

    virtual ~MeshComponent() = default;

    /* Component Specific */

    void SetMesh( const std::string &inFileName );

    std::string GetMesh() const;

    /* Life-Cycle Methods */

    void Initialize() override;

    void Update() override;

    void Destroy() override;

private:
    std::string mFileName;
};

#endif //_MESH_COMPONENT_HPP_