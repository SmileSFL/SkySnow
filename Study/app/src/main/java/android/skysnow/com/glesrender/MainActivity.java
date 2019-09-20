package android.skysnow.com.glesrender;

import android.skysnow.com.glesrender.GLESBase.GLESView;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity
{
    private GLESView mEsView;
    private AssetToSdcard mAssetToSdcard;
    private String mAssetsPath = "SkySnowResources";
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        mAssetToSdcard = new AssetToSdcard(this);
        mAssetToSdcard.copyAssetsDir2Phone(mAssetsPath);

        mEsView = new GLESView(this);
        setContentView(mEsView);
    }

    @Override
    protected void onPause() {
        super.onPause();
        mEsView.onPause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        mEsView.onResume();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        mEsView.release();
    }


}
