//
// Created by liuqian8 on 2019/8/8.
//
#include "Texture2D.h"
#include "Image.h"
Texture2D::Texture2D()
{

}

Texture2D::~Texture2D()
{

}

unsigned Texture2D::createTexture2D(Image* image)
{
    glGenTextures(1, &textureId_);
    glBindTexture(GL_TEXTURE_2D, textureId_);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    unsigned format = 0;
    switch (image->getImageComponents())
    {
        case 1:
            format = GL_R8;
            break;
        case 2:
            format = GL_RG8;
            break;
        case 3:
            format = GL_RGB;
            break;
        case 4:
            format = GL_RGBA;
            break;
        default:
            break;
    }
    glTexImage2D(GL_TEXTURE_2D, 0, format, image->getImageWidth(), image->getImageHeight(), 0, getExternalFormat(format), getDataType(format), image->getData());

    glBindTexture(GL_TEXTURE_2D, 0);
    return textureId_;
}

unsigned Texture2D::createTexture2D(unsigned format,int width,int height)
{
    glGenTextures(1, &textureId_);
    glBindTexture(GL_TEXTURE_2D, textureId_);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    if(format == GL_DEPTH_COMPONENT16 || format == GL_DEPTH_COMPONENT24 || format == GL_DEPTH_COMPONENT32F)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT32F, width, height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_NONE);
    }else{
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, GL_RGBA, GL_FLOAT, nullptr);
    }
    return textureId_;
}
