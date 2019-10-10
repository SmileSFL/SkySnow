//
// Created by liuqian8 on 2019/8/8.
//
#include "EngineEntry.h"

EngineEntry::EngineEntry(Context* context):
    context_(context),
    exampleObject_(nullptr),
    isInitial_(false),
    width_(0),
    height_(0)
{
}

EngineEntry::~EngineEntry()
{
    if(exampleObject_)
    {
        delete exampleObject_;
        exampleObject_ = nullptr;
    }

    if(context_)
    {
        delete context_;
        context_ = nullptr;
    }

//    if(mainThread_)
//    {
//        delete mainThread_;
//        mainThread_ = nullptr;
//    }
}

void EngineEntry::setViewSize(int width,int height)
{
    width_ = width;
    height_ = height;
}

//void EngineEntry::startMainThread()
//{
//
//    mainThread_ = new MainThread();
//
//    context_->setMainThread(mainThread_);
//
//    mainThread_->run();
//}

void EngineEntry::renderOneFrame()
{
    if(exampleObject_ != nullptr && !isInitial_)
    {
        exampleObject_->initial(width_,height_);
        isInitial_ = true;
    }
    if(exampleObject_ != nullptr && isInitial_)
        exampleObject_->drawFrame();
}