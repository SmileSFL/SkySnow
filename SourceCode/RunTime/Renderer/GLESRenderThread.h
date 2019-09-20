//
// Created by liuqian8 on 2019/8/30.
//
#pragma once
#include "RenderThreadBase.h"
class CommandList;
class GLESRenderThread:public RenderThreadBase
{
public:
    GLESRenderThread();

    ~GLESRenderThread();

    virtual void beginRender();

    virtual void present();

//    virtual void acqiureThreadOwnerShip();
//
//    virtual void releaseThreadOwnership();

    virtual void runOneThreadCommand();


protected:
    CommandList* commandQueue_;
};
