//
// Created by liuqian8 on 2019/8/9.
//
#pragma once

class Pass
{
public:
    Pass();

    virtual ~Pass();

    void setDepthModel();

    void setBlendMode();

    void start();

    void end();
protected:

};
