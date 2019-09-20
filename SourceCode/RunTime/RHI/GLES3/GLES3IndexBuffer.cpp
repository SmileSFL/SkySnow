//
// Created by liuqian8 on 2019/8/12.
//
#include "GLES3IndexBuffer.h"

IndexBuffer::IndexBuffer()
{

}

IndexBuffer::~IndexBuffer()
{

}

bool IndexBuffer::setSize(unsigned indexCount, bool largeIndices, bool dynamic)
{
    indexCount_ =indexCount;
    indexSize_  = (unsigned)(largeIndices? sizeof(unsigned): sizeof(unsigned short));
    dynamic_    = dynamic;

    return create();
}

bool IndexBuffer::setData(const void *data)
{
    if(!data)
    {
        LOGE("Null pointer for index buffer data.");
        return false;
    }
    if(!indexSize_)
    {
        return false;
    }
    if(gpuHandle_)
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gpuHandle_);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount_ * indexSize_, data, dynamic_ ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
    }
    return true;
}

bool IndexBuffer::create()
{

    if(!indexCount_)
    {
        LOGE("index buffer indexCount is null.");
        return false;
    }

    if(!gpuHandle_)
        glGenBuffers(1,&gpuHandle_);
    if(!gpuHandle_)
    {
        LOGE("Failed to create index buffer");
        return false;
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gpuHandle_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount_ * indexSize_, nullptr, dynamic_ ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);

    return true;
}