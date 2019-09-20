//
// Created by liuqian8 on 2019/8/8.
//
#pragma once
#include "Texture.h"
class Texture2D:public Texture
{
public:
    Texture2D();

    ~Texture2D();

    unsigned createTexture2D(Image* image);

    unsigned createTexture2D(unsigned format,int width,int height);

};
