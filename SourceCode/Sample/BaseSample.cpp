//
// Created by liuqian8 on 2019/8/8.
//

#include "BaseSample.h"

BaseSample::BaseSample(Context *context):
    Application(context)
{

}

BaseSample::~BaseSample()
{

}

void BaseSample::initialScence(int width, int height)
{
    testMainThread_ = (MainThread*)context_->getMainThread();
    glesRenderThread_ = testMainThread_->getRender();
    glesRenderThread_->startRenderThread();
}
//渲染线程
void BaseSample::renderOneFrame(float frameTime)
{
    LOGE("BaseSample renderOneFrame.");
    glesRenderThread_->runOneThreadCommand();
}
