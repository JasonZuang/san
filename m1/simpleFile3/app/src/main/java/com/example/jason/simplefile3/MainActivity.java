package com.example.jason.simplefile3;

import android.content.Context;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;

/*
    I had help from some online rescources
    http://stackoverflow.com/questions/9544737/read-file-from-assets
    http://stackoverflow.com/questions/30417810/reading-from-a-text-file-in-android-studio-java
    https://www.tutorialspoint.com/java/java_files_io.htm
 */
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        File file = new File(Environment.getExternalStorageDirectory(),"new.txt");
        BufferedReader is = null;
        FileWriter os;
        try{
            is = new BufferedReader( new InputStreamReader (getAssets().open("smalltext.txt"),"UTF-8"));
            os = new FileWriter(file);
            String a ="";
            while((a = is.readLine()) != null ) {
                System.out.println(a);//prints to debugger
                os.write(a);
            }
            os.close();
            file.delete();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if(is != null)
            {
                try {
                    is.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
