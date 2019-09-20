//
// Created by liuqian8 on 2019/5/9.
//

#include "Rect2D.h"
#include "Texture2D.h"
Rect2D::Rect2D():
        RectHandle(nullptr),
        lightProgram_(nullptr)
{

}

Rect2D::~Rect2D()
{
    if(lightProgram_)
    {
        delete lightProgram_;
        lightProgram_ = NULL;
    }

    if(RectHandle)
    {
        delete RectHandle;
        RectHandle = NULL;
    }
}

void Rect2D::CreateRect2D(Context *context,int width,int height)
{
    //显示GBuffer数据的矩形数据。
    RectHandle = new Rect();

    file_ = new File(context);
    string vslData = file_->getStringFromFileAssets("SkySnowResources/CoreData/Shaders/deferredLightVs.glsl");
    string fslData = file_->getStringFromFileAssets("SkySnowResources/CoreData/Shaders/deferredLightFs.glsl");
    lightProgram_ = new CaseShaderProgram();
    lightProgram_->link(vslData,fslData);

    RectHandle->viewport.x = (float)width;
    RectHandle->viewport.y = (float)height;
}

void Rect2D::DrawRect2D(std::vector<Texture2D*> gbuffer)
{
//    uiRect show
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE);
    glCullFace(GL_FRONT);
    glDepthMask(GL_FALSE);
    glDepthFunc(GL_GEQUAL);
    lightProgram_->use();

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gbuffer[0]->getGPUHandle());
    lightProgram_->setParamater("gposition",0);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, gbuffer[1]->getGPUHandle());
    lightProgram_->setParamater("gnormal",1);

    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, gbuffer[2]->getGPUHandle());
    lightProgram_->setParamater("gcolor",2);

    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, gbuffer[3]->getGPUHandle());
    lightProgram_->setParamater("gdepth",3);


    lightProgram_->setParamater("u_Viewport",RectHandle->viewport);
    lightProgram_->setParamater("lightPosition",RectHandle->lightPos);
    lightProgram_->setParamater("u_eyePosition",RectHandle->eyePosition);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, RectHandle->positions);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, RectHandle->texcoords);
    glDrawElements(GL_TRIANGLES, 6,GL_UNSIGNED_INT,RectHandle->index);

    glDisable(GL_BLEND);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LESS);
    glCullFace(GL_BACK);
}
