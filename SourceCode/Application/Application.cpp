//
// Created by liuqian8 on 2019/8/8.
//
#include "Application.h"
Application::Application(Context *context):
        context_(context),
        time_(new SNTime()),
        frameTime_(0),
        startTime_(0),
        endTime_(0),
        count_(0)
{

}

Application::~Application()
{
    if(time_)
    {
        delete time_;
        time_ = nullptr;
    }

}

void Application::initial(int width, int height)
{
    initialScence(width,height);
}

void Application::drawFrame()
{
    if(count_ == 9)
    {
        endTime_ = time_->getCurrentTime();
        frameTime_ = (endTime_ - startTime_)/9.0f;
        fps_ = 1000/frameTime_;

        LOGI("Render One Frame FPS :%f",fps_);
        LOGI("Render One Frame Time:%f",frameTime_);
        count_ = 0;
        startTime_ = endTime_;
    }
    count_ = (count_ + 1) % 10;

    renderOneFrame(frameTime_);
}
