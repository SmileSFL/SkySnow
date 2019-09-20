//
// Created by liuqian8 on 2019/8/8.
//
#pragma once
#include "Object.h"
class Texture2D;
class FrameBufferObject:public Object
{
public:
    FrameBufferObject();

    virtual ~FrameBufferObject();

    unsigned initFrameBufferObject();

    void drawBuffer(unsigned count,int* buffers);

    void bind(unsigned target);

    void unBind(unsigned target);

    unsigned getGPUHandle();

    void bindColorAttachment(unsigned target,unsigned index, unsigned textarget, Texture2D* object, bool isRenderBuffer = false);

    void bindDepthAttachment(unsigned target,Texture2D* object, bool isRenderBuffer = false);

    void bindStencilAttachment(unsigned target,Texture2D* object, bool isRenderBuffer = false);

protected:
    unsigned gpuHandle_;
};
