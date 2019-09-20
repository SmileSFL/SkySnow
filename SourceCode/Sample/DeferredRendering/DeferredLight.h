//
// Created by liuqian8 on 2019/8/8.
//
#pragma once

#include "Application.h"
#include "File.h"
#include "Image.h"
#include "Texture2D.h"
#include "CaseShaderProgram.h"
#include "FrameBufferObject.h"
#include "Pass.h"
#include "StaticModel.h"
#include "Camera.h"
#include "Rect2D.h"
#include "Model.h"
class DeferredLight:public Application
{
public:
    DeferredLight(Context* context);

    ~DeferredLight();

protected:
    virtual void initialScence(int width,int height) override ;

    virtual void renderOneFrame(float frameTime) override;


private:
    File* file_;

    Image* image_;

    Texture2D* texture2D_;

    Texture2D* textureColor0_;
    Texture2D* textureColor1_;
    Texture2D* textureColor2_;
    Texture2D* textureColor3_;
    Texture2D* textureDepth_;

    CaseShaderProgram* mrtProgram_;

//    CaseShaderProgram* lightProgram_;

    FrameBufferObject* frameBufferObject_;

    GLenum                      drawBuffers[3];

    Pass* deferredPass_;

    Pass* lightPass_;

//    StaticModel* staticModel_;
    Model* model_;

    Rect2D*                     rect2D;

    glm::mat4 ModelMatrix_;

    glm::mat4 MVPMatrix_;

    Camera* camera_;
    std::vector<Texture2D*> textureList_;
};
