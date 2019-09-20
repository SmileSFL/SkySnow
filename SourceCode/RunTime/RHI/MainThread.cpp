//
// Created by liuqian8 on 2019/8/30.
//
#include "MainThread.h"
#include "Common.h"
MainThread::MainThread()
{
    glesRenderThread_ = new GLESRenderThread();
}

MainThread::~MainThread()
{

}

void MainThread::threadFunction()
{
    while(1)
    {
        update();
    }
}

void MainThread::update()
{
    for(int i = 0 ; i < 4000;i ++)
    {
        model_ = glm::translate(glm::vec3(0.0f,0.0f,0.0f))*glm::rotate(0.0f,glm::vec3(0,1,0))
                 *glm::rotate(0.0f,glm::vec3(1,0,0))*glm::scale(glm::vec3(1.5f,1.5f,1.5f));
        eyeMat_ = glm::lookAt(glm::vec3(0,10,0),glm::vec3(0,0,0),glm::vec3(0,1,0));
        projectMat_ = glm::perspective(glm::radians(120.0f), (float)1080 / (float)1920, 0.1f, 100.0f);
    }
    glesRenderThread_->beginRender();

    glesRenderThread_->present();
}
