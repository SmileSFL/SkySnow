//
// Created by liuqian8 on 2019/8/8.
//
#pragma once
#include "Application.h"
#include "Context.h"
#include "GLESRenderThread.h"
#include "MainThread.h"
using namespace std;
class BaseSample: public Application
{
public:
    BaseSample(Context* context);

    ~BaseSample();

protected:
    virtual void initialScence(int width,int height) override ;

    virtual void renderOneFrame(float frameTime) override;

private:
    GLESRenderThread* glesRenderThread_;
    MainThread* testMainThread_;
};
