//
// Created by liuqian8 on 2019/8/8.
//
#include "DeferredLight.h"
#include "Common.h"
#include "CaseShaderProgram.h"
#include "glm/ext.hpp"
DeferredLight::DeferredLight(Context* context):
    Application(context),
    frameBufferObject_(nullptr),
    file_(nullptr),
    mrtProgram_(nullptr),
    image_(nullptr),
    deferredPass_(nullptr),
    lightPass_(nullptr),
    rect2D(nullptr),
    camera_(nullptr)
{

}

DeferredLight::~DeferredLight()
{

}

void DeferredLight::initialScence(int width, int height)
{
    glViewport(0,0,width,height);

    image_ = new Image();
    image_->loadImage("/sdcard/SkySnowResources/CoreData/Textures/fish.png");

    texture2D_ = new Texture2D();
    texture2D_->createTexture2D(image_);

    textureColor0_ = new Texture2D();
    textureColor0_->createTexture2D(GL_RGBA32F,width,height);

    textureColor1_ = new Texture2D();
    textureColor1_->createTexture2D(GL_RGBA32F,width,height);

    textureColor2_ = new Texture2D();
    textureColor2_->createTexture2D(GL_RGBA32F,width,height);

    textureColor3_ = new Texture2D();
    textureColor3_->createTexture2D(GL_RGBA32F,width,height);

    textureDepth_ = new Texture2D();
    textureDepth_->createTexture2D(GL_DEPTH_COMPONENT32F,width,height);

    file_ = new File(context_);
    std::string vsData = file_->getStringFromFileAssets("SkySnowResources/CoreData/Shaders/deferredVertex.glsl");
    std::string fsData = file_->getStringFromFileAssets("SkySnowResources/CoreData/Shaders/deferredFragment.glsl");
    mrtProgram_ = new CaseShaderProgram();
    mrtProgram_->link(vsData,fsData);


    frameBufferObject_ = new FrameBufferObject();

    frameBufferObject_->initFrameBufferObject();
    frameBufferObject_->bind(GL_FRAMEBUFFER);
    frameBufferObject_->bindColorAttachment(GL_DRAW_FRAMEBUFFER,0,GL_TEXTURE_2D,textureColor0_);//vPosition
    frameBufferObject_->bindColorAttachment(GL_DRAW_FRAMEBUFFER,1,GL_TEXTURE_2D,textureColor1_);//vNormal
    frameBufferObject_->bindColorAttachment(GL_DRAW_FRAMEBUFFER,2,GL_TEXTURE_2D,textureColor2_);//albedo
    frameBufferObject_->bindColorAttachment(GL_DRAW_FRAMEBUFFER,3,GL_TEXTURE_2D,textureColor3_);//vTexCoord
    frameBufferObject_->bindDepthAttachment(GL_DRAW_FRAMEBUFFER,textureDepth_,false);


    drawBuffers[0] = GL_COLOR_ATTACHMENT0;
    drawBuffers[1] = GL_COLOR_ATTACHMENT1;
    drawBuffers[2] = GL_COLOR_ATTACHMENT2;
    drawBuffers[3] = GL_COLOR_ATTACHMENT3;
    frameBufferObject_->drawBuffer(4,(int*)drawBuffers);
    frameBufferObject_->unBind(GL_FRAMEBUFFER);
    deferredPass_ = new Pass();

    lightPass_ = new Pass();

//    staticModel_ = new StaticModel();
//    bool load = staticModel_->beginLoad("/sdcard/SkySnowResources/Data/Models/fish.obj");

    model_ = new Model();
    bool load =  model_->beginLoad("/sdcard/SkySnowResources/Data/Models/fish.obj");
    if(load)
    {
        LOGI("加载模型成功。");
    }else{
        LOGE("加载模型失败。");
    }

    MVPMatrix_ = glm::mat4(1.0f);
    ModelMatrix_ = glm::mat4(1.0f);

    camera_ = new Camera();

    float pi = 3.1415926f;

    ModelMatrix_ = glm::translate(glm::vec3(0.0f,0.0f,0.0f))*
            glm::rotate(0.0f,glm::vec3(0,1,0))* glm::rotate(0.0f,glm::vec3(1,0,0))*
            glm::scale(glm::vec3(0.05,0.05f,0.05));

    camera_->setCameraLookAt(glm::vec3(0,-1,-1));
    camera_->setCameraPosition(glm::vec3(0,1,5));
    camera_->setCameraUp(glm::vec3(0,1,0));

    MVPMatrix_ = camera_->getFrustum()*camera_->getCamera()* ModelMatrix_;
    rect2D = new Rect2D();
    rect2D->CreateRect2D(context_,width,height);

    textureList_.push_back(textureColor0_);
    textureList_.push_back(textureColor1_);
    textureList_.push_back(textureColor2_);
    textureList_.push_back(textureDepth_);

    textureList_.push_back(textureColor3_);

    LOGI("Engine Sample initial.");
}

void DeferredLight::renderOneFrame(float frameTime)
{
    frameBufferObject_->bind(GL_DRAW_FRAMEBUFFER);
    glDepthMask(GL_TRUE);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
    deferredPass_->start();
    mrtProgram_->use();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture2D_->getGPUHandle());

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), model_->LoadedVertices.data());
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (reinterpret_cast<char*>(model_->LoadedVertices.data()) + 3 * sizeof(GL_FLOAT)));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GL_FLOAT), (reinterpret_cast<char*>(model_->LoadedVertices.data()) + 6 * sizeof(GL_FLOAT)));
    mrtProgram_->setParamater("uMVPMatix", MVPMatrix_);
    mrtProgram_->setParamater("uModelMatix", ModelMatrix_);
    glDrawElements(GL_TRIANGLES, model_->LoadedIndices.size(),GL_UNSIGNED_INT,model_->LoadedIndices.data());
    glBindTexture(GL_TEXTURE_2D,0);
    glUseProgram(0);
    deferredPass_->end();
    frameBufferObject_->unBind(GL_DRAW_FRAMEBUFFER);
    glDepthMask(GL_FALSE);
    glDisable(GL_DEPTH_TEST);

    lightPass_->start();
    rect2D->DrawRect2D(textureList_);
    lightPass_->end();
}
