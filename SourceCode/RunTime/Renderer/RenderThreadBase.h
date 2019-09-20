//
// Created by liuqian8 on 2019/8/23.
//
#pragma once
//#include "GLES3RenderSystem.h"
#include "SNSemaphore.h"

enum WaitType
{
    WaitType_Common,
    WaitType_OnwerShip,
    WaitType_Present,
    WaitType_CreateShader,
    WaitType_CreateVBO,
    WaitType_CreateTexture,

    WaitType_Max
};

class RenderThreadBase
{
public:
    RenderThreadBase();

    virtual ~RenderThreadBase();

    //开启渲染线程
    void startRenderThread();

    //执行队列中已经存在的渲染命令
    virtual void runOneThreadCommand() = 0;

    void waitForSignal(WaitType waitType = WaitType_Common) //拿球
    {
        _waitSem[waitType].waitForSignal();
    }
    void signal(WaitType waitType = WaitType_Common) //放球
    {
        _waitSem[waitType].signal();
    }
    void WaitForPresent()
    {
        waitForSignal(WaitType_Present);
    }
    void signalPresent()
    {
        signal(WaitType_Present);
        isInPresenting_ = false;
    }
    void waitForOwnerShip()
    {
        waitForSignal(WaitType_OnwerShip);
    }
    void signalOnwerShip()
    {
        signal(WaitType_OnwerShip);
    }

protected:
//    GLES3RenderSystem* rhiGLES3RenderSystem_;
    bool  threaded_;
    bool isInPresenting_;

private:
    SNSemaphore _waitSem[WaitType_Max];
};
