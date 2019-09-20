//
// Created by liuqian8 on 2019/8/12.
//
#pragma once
#include "RenderResource.h"
class IndexBuffer:public RenderResource
{
public:
    IndexBuffer();

    virtual ~IndexBuffer();

    bool setSize(unsigned indexCount,bool largeIndices,bool dynamic = false);

    bool setData(const void* data);

    unsigned getIndexCount() const {return indexCount_;}

    unsigned getIndexSize() const {return indexSize_;}

private:
    bool create();

    unsigned indexCount_;

    unsigned indexSize_;

    bool dynamic_;
};
