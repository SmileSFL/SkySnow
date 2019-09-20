//
// Created by liuqian8 on 2019/8/8.
//
#include "Texture.h"

Texture::Texture():
    textureId_(0)
{

}

Texture::~Texture()
{

}

unsigned Texture::getExternalFormat(unsigned format)
{
    if (format == GL_DEPTH_COMPONENT16 || format == GL_DEPTH_COMPONENT24 || format == GL_DEPTH_COMPONENT32F)
        return GL_DEPTH_COMPONENT;
    else if (format == GL_DEPTH24_STENCIL8 || format == GL_DEPTH32F_STENCIL8)
        return GL_DEPTH_STENCIL;
    else if (format == GL_R8 || format == GL_R16F || format == GL_R32F)
        return GL_RED;
    else if (format == GL_RG8 || format == GL_RG16F || format == GL_RG32F)
        return GL_RG;
    else if (format == GL_RGBA16F || format == GL_SRGB_ALPHA_EXT)
        return GL_RGBA;
    else if (format == GL_SRGB_EXT)
        return GL_RGB;
    else
        return format;
}

unsigned Texture::getDataType(unsigned format)
{
    if (format == GL_DEPTH_COMPONENT || format == GL_DEPTH_COMPONENT24_OES)
        return GL_UNSIGNED_INT;
    else if (format == GL_DEPTH_COMPONENT16)
        return GL_UNSIGNED_SHORT;
    else
        return GL_UNSIGNED_BYTE;
}

unsigned Texture::getGPUHandle()
{
    return textureId_;
}
