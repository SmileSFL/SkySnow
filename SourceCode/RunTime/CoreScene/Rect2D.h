//
// Created by liuqian8 on 2019/5/9.
//

#pragma once

#include "File.h"
#include "Context.h"
#include "CaseShaderProgram.h"
class Texture2D;
struct Rect
{
    glm::vec2 viewport;

    glm::vec3 lightPos = glm::vec3(-8.0f,6.0f,-5.0f);
    glm::vec3 eyePosition = glm::vec3(5.0f,1.0f,-1.0f);

    float positions[8]=
    {
            1,1,
            1,-1,
            -1,-1,
            -1,1
    };
    float texcoords[8] =
    {
            1,1,
            1,0,
            0,0,
            0,1
    };
    int index[6] =
    {
            0,1,2,
            0,2,3
    };


};

class Rect2D
{
public:
    Rect2D();
    ~Rect2D();

    void CreateRect2D(Context* context,int width,int height);

    void DrawRect2D(std::vector<Texture2D*> gbuffer);

protected:
    Rect*                       RectHandle;
    File* file_;
    CaseShaderProgram*          lightProgram_;
};
