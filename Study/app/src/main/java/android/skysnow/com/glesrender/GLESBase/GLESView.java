package android.skysnow.com.glesrender.GLESBase;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;
import android.view.MotionEvent;

/**
 * Created by liuqian8 on 2019/8/8.
 */

public class GLESView extends GLSurfaceView
{
    private GLESRenderer mRender;
    private GLESNative mGLESNative;
    public GLESView(Context context)
    {
        this(context, (AttributeSet)null);
    }

    public GLESView(Context context, AttributeSet attributeSet)
    {
        super(context, attributeSet);
        //先启动主线程
        mGLESNative = new GLESNative(context);
        mGLESNative.startMainThread();
        //然后启动渲染线程
        mRender = new GLESRenderer(mGLESNative);
        super.setEGLContextClientVersion(3);
        super.setEGLConfigChooser(8,8,8,8,24,8);
        setPreserveEGLContextOnPause(true);
        setRenderer(mRender);
        setRenderMode(GLSurfaceView.RENDERMODE_CONTINUOUSLY);
    }

    public void release()
    {
        if(mRender != null)
            mRender.release();
    }

    @Override
    public boolean onTouchEvent(MotionEvent e)
    {
        return mRender.onTouchEvent(e);
    }
}
