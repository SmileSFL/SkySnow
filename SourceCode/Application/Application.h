//
// Created by liuqian8 on 2019/8/8.
//
#pragma once
#include "Context.h"
#include "SNTime.h"
class Application
{
public:
    Application(Context* context);

    virtual ~Application();

    void initial(int width,int height);

    void drawFrame();
protected:
    //渲染线程初始化
    virtual void initialScence(int width,int height) = 0;
    //渲染线程开始渲染
    virtual void renderOneFrame(float frameTime) = 0;

    Context* context_;
private:
    SNTime* time_;
    long long startTime_;
    long long  endTime_;
    float frameTime_;
    int count_;
    float fps_;
};
