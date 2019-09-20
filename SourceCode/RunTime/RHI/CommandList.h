//
// Created by liuqian8 on 2019/8/23.
//
#pragma once
#include "Common.h"
#include "GLES3RenderSystem.h"
#include "SNSemaphore.h"

template <class T> class CommandQueue
{
public:
    CommandQueue():
            in_(0),
            out_(0)
    {
    }

    void push(T v)
    {
        int next = (in_ +1 )%Max_Size;
        while(next == out_)
        {
            writeSem_.waitForSignal();
        }
        arr_[in_] = v;
        in_ = next;
        readSem_.signal();
    }

    T pop()
    {
        while(out_ == in_)
        {
            readSem_.waitForSignal();
        }
        T v = arr_[out_];
        out_ = (out_ + 1) % Max_Size;
        writeSem_.signal();
        return v;
    }
private:
    const static int Max_Size = 1024;

    T arr_[Max_Size];

    int in_;

    int out_;

    SNSemaphore readSem_;

    SNSemaphore writeSem_;
};
class GLESRenderThread;
class Command
{
public:
    virtual void execute(GLESRenderThread* renderSystem) = 0;

    virtual ~Command(){}

    virtual void onExecuteEnd(GLESRenderThread* renderSystem){}
};

class CommandBase
{
public:
    virtual ~CommandBase(){}

    virtual Command* pop() = 0;

    virtual void push(Command* cmd) = 0;

    virtual bool empty() const = 0;
};
class CommandList:public CommandBase
{
public:

    virtual Command* pop()
    {
        return commandQueue_.pop();
    }

    virtual void push(Command* cmd)
    {
        commandQueue_.push(cmd);
    }

    virtual bool empty() const
    {
        return false;
    }

private:
    CommandQueue<Command*> commandQueue_;
};
