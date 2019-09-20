//
// Created by liuqian8 on 2019/8/8.
//
#pragma once
#if PLATFORM == PLATFORM_ANDROID
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#endif
#include "Common.h"
class Thread;
class Context
{
public:
    Context();

    ~Context();

    void setMainThread(Thread* mainThread)
    {
        mainThread_ = mainThread;
    }
    Thread* getMainThread()
    {
        return mainThread_;
    }

#if PLATFORM == PLATFORM_ANDROID
    void setSetAssetManager(AAssetManager *mgr)
    {
        if(nullptr == mgr)
            LOGE("AAssetManager is null pointer. -----Context.cpp.");
        mgr_ = mgr;
    }

    AAssetManager* getAAssetManager()
    {
        if(nullptr == mgr_)
            LOGE("AAssetManager is null pointer. -----Context.cpp.");
        return mgr_;
    }
#endif
protected:
#if PLATFORM == PLATFORM_ANDROID
    AAssetManager* mgr_;
#endif

private:
    Thread* mainThread_;
};
