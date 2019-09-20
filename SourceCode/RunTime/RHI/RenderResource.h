//
// Created by liuqian8 on 2019/8/29.
//
#pragma once

#include "Common.h"
class RenderResource
{
public:
    RenderResource();

    virtual ~RenderResource();

protected:
    unsigned gpuHandle_;
};
