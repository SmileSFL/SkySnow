//
// Created by liuqian8 on 2019/8/9.
//
#pragma once
#include "vec2.hpp"
#include "vec3.hpp"
#include <string>
#include <vector>

struct Vertex
{
    // Position Vector
    glm::vec3 Position;

    // Normal Vector
    glm::vec3 Normal;

    // Texture Coordinate Vector
    glm::vec2 TextureCoordinate;
};
class Model
{
public:
    Model();

    virtual ~Model();

    bool beginLoad(std::string path);



    std::vector<Vertex> LoadedVertices;
    // Loaded Index Positions
    std::vector<unsigned int> LoadedIndices;
};