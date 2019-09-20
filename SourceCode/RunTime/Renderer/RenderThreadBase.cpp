//
// Created by liuqian8 on 2019/8/23.
//
#include "RenderThreadBase.h"

RenderThreadBase::RenderThreadBase():
        threaded_(false),
        isInPresenting_(false)
{
}

RenderThreadBase::~RenderThreadBase()
{

}

void RenderThreadBase::startRenderThread()
{
//    signal();
//    if(threaded_)
//    {
//        runOneThreadCommand();
//    }
//    waitForSignal();
}

