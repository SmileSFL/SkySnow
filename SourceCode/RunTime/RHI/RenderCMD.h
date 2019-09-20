//
// Created by liuqian8 on 2019/8/30.
//
#pragma once

#include "Common.h"
#include "GLESRenderThread.h"
#include "CommandList.h"
class ClearCMD:public Command
{
public:
    virtual void execute(GLESRenderThread* renderSystem)
    {
        LOGE("ClearCMD 执行渲染的命令。");
    }
};

class PresentCMD:public Command
{
public:
    virtual void execute(GLESRenderThread* renderSystem)
    {
        LOGE("PresentCMD 执行渲染的命令。");
    }

    void onExecuteEnd(GLESRenderThread* threadDevice)
    {
        threadDevice->signalPresent();
    }
};

class AcquireOwnerShipCMD : public Command
{
public:
    void execute(GLESRenderThread* device)
    {
        LOGE("AcquireOwnerShipCMD 执行渲染的命令。");
    }
    void onExecuteEnd(GLESRenderThread* threadDevice)
    {
        threadDevice->signalOnwerShip();
    }
};

class ReleasOwnerShipCMD : public Command
{
public:
    void execute(GLESRenderThread* device)
    {
        LOGE("ReleasOwnerShipCMD 执行渲染的命令。");
    }
    void onExecuteEnd(GLESRenderThread* threadDevice)
    {
        threadDevice->signalOnwerShip();
    }
};
