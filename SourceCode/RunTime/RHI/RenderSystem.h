//
// Created by liuqian8 on 2019/8/12.
//
#pragma once


enum PrimitiveType
{
    TRIANGLE_LIST = 0,
    LINE_LIST,
    POINT_LIST,
    TRIANGLE_STRIP,
    LINE_STRIP,
    TRIANGLE_FAN
};

class RenderSystem
{
public:
    RenderSystem();

    virtual ~RenderSystem();

    virtual void beginRender() = 0;

    virtual void render(PrimitiveType type) = 0;

    virtual void endRender() = 0;

protected:

};
