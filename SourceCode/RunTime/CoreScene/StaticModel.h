//
// Created by liuqian8 on 2019/8/9.
//
#pragma once
#include "vec2.hpp"
#include "vec3.hpp"
#include <string>
#include <vector>
class Model;
class StaticModel
{
public:
    StaticModel();

    virtual ~StaticModel();

    bool beginLoad(std::string path);

    void setModel(Model* model);
protected:
    Model* model_;
};
