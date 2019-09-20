//
// Created by liuqian8 on 2019/8/12.
//
#pragma once
#include "RenderSystem.h"
#include <vector>
class IndexBuffer;
class VertexBuffer;
class GLES3RenderSystem:public RenderSystem
{
public:
    GLES3RenderSystem();

    virtual ~GLES3RenderSystem();
    //设置索引数据
    void setIndexBuffer(IndexBuffer* indexBuffer, unsigned indexCount, unsigned indexStart = 0);
    //设置顶点数据
    void setVertexBuffer(VertexBuffer* vertexBuffer, unsigned vertexCount, unsigned vertexStart = 0);
    //唤醒渲染线程
    void beginRender();
    //将主线程中的渲染指令更新到渲染线程中。
    void updata();
    //渲染线程执行渲染命令
    virtual void render(PrimitiveType type = TRIANGLE_LIST) override ;
    //渲染线程挂起等待主线程更新渲染命令队列
    void endRender();
private:
    IndexBuffer* indexBuffer_;
    VertexBuffer* vertexBuffer_;
    unsigned indexStart_;
    unsigned indexCount_;
    unsigned vertexStart_;
    unsigned vertexCount_;
};
