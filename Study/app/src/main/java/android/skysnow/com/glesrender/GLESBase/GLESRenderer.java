package android.skysnow.com.glesrender.GLESBase;

import android.content.Context;
import android.opengl.GLES30;
import android.opengl.GLSurfaceView;
import android.util.Log;
import android.view.MotionEvent;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**
 * Created by liuqian8 on 2019/8/8.
 */

public class GLESRenderer implements GLSurfaceView.Renderer
{
    private GLESNative mGLESNative;
    public GLESRenderer(GLESNative glesNative)
    {
        mGLESNative = glesNative;
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config)
    {
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height)
    {
        mGLESNative.setViewSize(width,height);
        mGLESNative.createSample();
    }

    @Override
    public void onDrawFrame(GL10 gl)
    {
        mGLESNative.renderOneFrame();
    }

    public boolean onTouchEvent(MotionEvent e)
    {
        return true;
    }

    public void release()
    {
        mGLESNative.engineRelease();
    }
}
