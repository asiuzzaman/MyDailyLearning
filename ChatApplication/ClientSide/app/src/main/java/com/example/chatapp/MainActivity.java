package com.example.chatapp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.content.Intent;

public class MainActivity extends AppCompatActivity  {
    private static final  String  TAG="MyChatMainActivity";
    private Button mButton;
    private EditText nickname;
    public static final String NICKNAME="usernickname";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        Log.d(TAG,"onCreate....");
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mButton=findViewById(R.id.enterchat);
        nickname =findViewById(R.id.nickname);

        mButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.d(TAG,"enterChat button...");
                if(!nickname.getText().toString().isEmpty()){
                    Intent intent=new Intent(MainActivity.this,ChatBoxActivity.class);
                    intent.putExtra(NICKNAME, nickname.getText().toString());
                    startActivity(intent);
                    nickname.setText(" ");
                }
            }
        });
    }
}
