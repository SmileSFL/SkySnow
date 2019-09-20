//
// Created by liuqian8 on 2019/8/8.
//
#include "FrameBufferObject.h"
#include "Texture2D.h"
FrameBufferObject::FrameBufferObject():
    gpuHandle_(0)
{
}

FrameBufferObject::~FrameBufferObject()
{

}

unsigned FrameBufferObject::initFrameBufferObject()
{
    glGenFramebuffers(1,&gpuHandle_);
    return gpuHandle_;
}

void FrameBufferObject::drawBuffer(unsigned count, int* buffers)
{
    glDrawBuffers(count, (GLenum*)buffers);
}

void FrameBufferObject::bind(unsigned target)
{
    glBindFramebuffer(target, gpuHandle_);
}

void FrameBufferObject::unBind(unsigned target)
{
    glBindFramebuffer(target, 0);
}

unsigned FrameBufferObject::getGPUHandle()
{
    return gpuHandle_;
}


void FrameBufferObject::bindColorAttachment(unsigned target,unsigned index, unsigned textarget, Texture2D* object,bool isRenderBuffer)
{
    if (!object)
        isRenderBuffer = false;

    if (!isRenderBuffer){
        glFramebufferTexture2D(target, GL_COLOR_ATTACHMENT0 + index, textarget, object->getGPUHandle(), 0);
    }else
        glFramebufferRenderbuffer(target, GL_COLOR_ATTACHMENT0 + index, GL_RENDERBUFFER, object->getGPUHandle());
}

void FrameBufferObject::bindDepthAttachment(unsigned target,Texture2D* object, bool isRenderBuffer)
{
    if (!object)
        isRenderBuffer = false;
    if (!isRenderBuffer)
        glFramebufferTexture2D(target, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, object->getGPUHandle(), 0);
    else
        glFramebufferRenderbuffer(target, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, object->getGPUHandle());
}

void FrameBufferObject::bindStencilAttachment(unsigned target,Texture2D* object, bool isRenderBuffer)
{
    if (!object)
        isRenderBuffer = false;
    if (!isRenderBuffer)
        glFramebufferTexture2D(target, GL_STENCIL_ATTACHMENT, GL_TEXTURE_2D, object->getGPUHandle(), 0);
    else
        glFramebufferRenderbuffer(target, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, object->getGPUHandle());
}
