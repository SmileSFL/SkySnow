//
// Created by liuqian8 on 2019/8/8.
//
#pragma once
#include "Object.h"
#include "Common.h"
class Image;

class Texture: public Object
{
public:
    Texture();

    virtual ~Texture();

    unsigned getGPUHandle();

protected:

    unsigned  getExternalFormat(unsigned format);

    unsigned getDataType(unsigned format);

    unsigned textureId_;
};
