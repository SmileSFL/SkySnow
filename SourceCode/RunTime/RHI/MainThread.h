//
// Created by liuqian8 on 2019/8/30.
//
#pragma once
#include "GLESRenderThread.h"
#include "Thread.h"

#include "ext.hpp"
#include "type_mat4x4.hpp"
#include "vec4.hpp"

class MainThread:public Thread
{
public:
    MainThread();

    ~MainThread();

    virtual void threadFunction() override;

    void update();

    GLESRenderThread* getRender()
    {
        return glesRenderThread_;
    }

private:
    GLESRenderThread* glesRenderThread_;

    glm::mat4 model_;
    glm::mat4 eyeMat_;
    glm::mat4 projectMat_;
};
