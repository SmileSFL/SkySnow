//
// Created by liuqian8 on 2019/8/12.
//
#pragma once
#include "RenderResource.h"
#include "Common.h"

class GLES3Texture:public RenderResource
{
public:
    GLES3Texture();

    virtual ~GLES3Texture();

protected:

    unsigned getExternalFormat(unsigned format);

    unsigned getDataType(unsigned format);
};
