//
// Created by liuqian8 on 2019/8/8.
//
#pragma once
#include "Application.h"
#include "Context.h"
#include "Common.h"
#include "MainThread.h"
class EngineEntry
{
public:
    EngineEntry(Context* context);

    ~EngineEntry();

    void setViewSize(int width,int height);

    void startMainThread();

    void renderOneFrame();

    template <class T> void createApplication()
    {
        if(exampleObject_)
        {
            delete exampleObject_;
            exampleObject_ = nullptr;
        }
        exampleObject_ = new T(context_);
    }

    template <class T> T* getApplication()
    {
        return static_cast<T*>(exampleObject_);
    }

private:
    Context* context_;
    Application* exampleObject_;
    bool isInitial_;
    int width_;
    int height_;

    MainThread* mainThread_;
};
