package android.skysnow.com.glesrender.GLESBase;

import android.content.Context;
import android.content.res.AssetManager;

/**
 * Created by liuqian8 on 2019/8/8.
 */

public class GLESNative
{
    static {
        System.loadLibrary("GLESRenderer");
    }
    private Context mContext;
    private long mEntryClassId;
    public GLESNative(Context context)
    {
        mContext = context;
    }

    public void createSample()
    {
        createSample(mEntryClassId);
    }

    public void startMainThread()
    {
        mEntryClassId = startMainThread(mContext.getAssets());
    }
    //设置视口的大小
    public void setViewSize(int width,int height)
    {
        setViewSize(mEntryClassId,width,height);
    }
    //引擎渲染每一帧
    public void renderOneFrame()
    {
        renderOneFrame(mEntryClassId);
    }
    //引擎回收
    public void engineRelease()
    {
        engineRelease(mEntryClassId);
    }

    //===========native方法

    protected native long startMainThread(AssetManager ass);

    protected native void setViewSize(long classId, int width, int height);

    protected native void renderOneFrame(long classId);

    protected native void engineRelease(long classId);

    protected native void createSample(long classId);
}
