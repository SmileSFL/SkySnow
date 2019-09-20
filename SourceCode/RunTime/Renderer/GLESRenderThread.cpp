//
// Created by liuqian8 on 2019/8/30.
//
#include "RenderCMD.h"
#include "CommandList.h"
#include "GLESRenderThread.h"

GLESRenderThread::GLESRenderThread()
{
    commandQueue_ = new CommandList();
}

GLESRenderThread::~GLESRenderThread()
{

}


void GLESRenderThread::beginRender()
{

}

void GLESRenderThread::present()
{
    if (isInPresenting_)
    {
        WaitForPresent();
    }
    isInPresenting_ = true;

    commandQueue_->push(new PresentCMD());
}

void GLESRenderThread::runOneThreadCommand()
{
    Command* cmd = commandQueue_->pop();
    cmd->execute(this);
    cmd->onExecuteEnd(this);
    delete cmd;
}
