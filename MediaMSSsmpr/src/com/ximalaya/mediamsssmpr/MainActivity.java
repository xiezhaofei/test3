package com.ximalaya.mediamsssmpr;


import com.example.mediamsssmpr.R;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;


public class MainActivity extends Activity {

	private TextView text;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        text = (TextView)findViewById(R.id.text1);
        MediaNS ns = new MediaNS();
        text.setText(ns.test());
    }

}
