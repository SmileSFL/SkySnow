package android.skysnow.com.glesrender;

import android.content.Context;
import android.os.Environment;
import android.widget.Toast;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

/**
 * Created by liuqian8 on 2019/8/8.
 */

public class AssetToSdcard
{
    private Context mContext;
    public AssetToSdcard(Context context)
    {
        mContext = context;
    }
    public void copyAssetsDir2Phone(String filePath) {
        try {
            String[] fileList = mContext.getAssets().list(filePath);
            if (fileList.length > 0) {//如果是目录
                File file = new File(mContext.getFilesDir().getAbsolutePath() + File.separator + filePath);
                file.mkdirs();//如果文件夹不存在，则递归
                for (String fileName : fileList) {
                    filePath = filePath + File.separator + fileName;

                    copyAssetsDir2Phone(filePath);

                    filePath = filePath.substring(0, filePath.lastIndexOf(File.separator));
//                    Log.e("oldPath", filePath);
                }
            } else {//如果是文件
                InputStream inputStream = mContext.getAssets().open(filePath);
                //getFilesDir() 获得当前APP的安装路径 /data/data/包名/files 目录
                File file = new File(Environment.getExternalStorageDirectory() + File.separator + filePath);
//                Log.i("SkySnow:", "file:" + file);
                if (!file.exists() || file.length() == 0) { // 文件不存在
                    File parent = file.getParentFile();
                    if (parent != null && !file.exists()) {
                        parent.mkdirs();
                    }
                    FileOutputStream fos = new FileOutputStream(file);
                    int len = -1;
                    byte[] buffer = new byte[1024];
                    while ((len = inputStream.read(buffer)) != -1) {
                        fos.write(buffer, 0, len);
                    }
                    fos.flush();
                    inputStream.close();
                    fos.close();
//                    showToast("文件夹数据复制完毕");
                } else {
//                    showToast("文件夹数据已存在，无需复制");
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
