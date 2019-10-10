#include <jni.h>
#include <string>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include "Context.h"
#include "EngineEntry.h"
#include "DeferredLight.h"
#include "Common.h"
#include "BaseSample.h"
#define JNI_METHOD(return_type, method_name) \
  JNIEXPORT return_type JNICALL              \
      Java_android_skysnow_com_glesrender_GLESBase_GLESNative_##method_name

#ifdef __cplusplus
extern "C" {
#endif

JNI_METHOD(long ,startMainThread)(JNIEnv *env,jobject jobject1,jobject assetManager)
{
    jobject assetManagerTemp_ = env->NewGlobalRef(assetManager);
    AAssetManager* mgr = AAssetManager_fromJava(env,assetManagerTemp_);

    Context* context = new Context();
    context->setSetAssetManager(mgr);

    EngineEntry* engineEntry = new EngineEntry(context);
//    engineEntry->startMainThread();
    return (uintptr_t)(engineEntry);
}

JNI_METHOD(void,setViewSize)(JNIEnv *env,jobject jobject1,long classId,jint width,jint height)
{
    EngineEntry* engineEntry = (EngineEntry*)(classId);
    engineEntry->setViewSize(width,height);
}

JNI_METHOD(void,renderOneFrame)(JNIEnv *env,jobject jobject1,jlong classId)
{
    EngineEntry* engineEntry = (EngineEntry*)(classId);
    engineEntry ->renderOneFrame();
}

JNI_METHOD(void,engineRelease)(JNIEnv *env,jobject jobject1,jlong classId)
{
    EngineEntry* engineEntry = (EngineEntry*)(classId);
    if(engineEntry != nullptr)
    {
        delete engineEntry;
        engineEntry = nullptr;
    }
}


JNI_METHOD(void,createSample)(JNIEnv *env,jobject jobject1,jlong classId)
{
    EngineEntry* engineEntry = (EngineEntry*)(classId);

    engineEntry->createApplication<DeferredLight>();
//    engineEntry->createApplication<BaseSample>();
}


#ifdef __cplusplus
}
#endif
