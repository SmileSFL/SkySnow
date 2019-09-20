//
// Created by liuqian8 on 2019/8/12.
//
#include "GLES3RenderSystem.h"
#include "GLES3IndexBuffer.h"
#include "GLES3VertexBuffer.h"
GLES3RenderSystem::GLES3RenderSystem():
        indexBuffer_(nullptr),
        vertexBuffer_(nullptr),
        indexStart_(0),
        indexCount_(0),
        vertexCount_(0),
        vertexStart_(0)
{

}

GLES3RenderSystem::~GLES3RenderSystem()
{

}

void GLES3RenderSystem::setIndexBuffer(IndexBuffer *indexBuffer, unsigned indexCount, unsigned indexStart)
{
    indexBuffer_ = indexBuffer;
    indexStart_ = indexStart;
    indexCount_ = indexCount;
}

void GLES3RenderSystem::setVertexBuffer(VertexBuffer *vertexBuffer,unsigned vertexCount, unsigned vertexStart)
{
    vertexBuffer_ = vertexBuffer;
    vertexCount_ = vertexCount;
    vertexStart_ = vertexStart;
}

void GLES3RenderSystem::beginRender()
{

}

void GLES3RenderSystem::updata()
{

}

void GLES3RenderSystem::render(PrimitiveType type)
{
    //索引法绘制
    if(indexBuffer_ && vertexBuffer_)
    {

    }else if(vertexBuffer_ != nullptr && indexBuffer_ == nullptr)//三角形卷绕法绘制
    {

    }
}

void GLES3RenderSystem::endRender()
{

}
