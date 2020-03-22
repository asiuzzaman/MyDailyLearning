package com.example.chatapp;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.DefaultItemAnimator;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.github.nkzawa.emitter.Emitter;
import com.github.nkzawa.socketio.client.IO;
import com.github.nkzawa.socketio.client.Socket;

import org.json.JSONException;
import org.json.JSONObject;

import java.net.URISyntaxException;
import java.util.ArrayList;
import java.util.List;

public class ChatBoxActivity extends AppCompatActivity {
    private static final String TAG="MyChatChatBoxActivity";
    public RecyclerView mRecycleView;
    public List<Message>mMessageList;
    public ChatBoxAdapter mChatBoxAdapter;
    public EditText messageText;
    public Button sendButton;
    public Socket mSocket;
    public String Nickname;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        Log.d(TAG,"onCreate ..");
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_chat_box);
        sendButton=findViewById(R.id.send);
        messageText=findViewById(R.id.message);
        Nickname= getIntent().getExtras().getString(MainActivity.NICKNAME);
        Toast.makeText(ChatBoxActivity.this,Nickname,Toast.LENGTH_SHORT).show();

        try {
            Log.d(TAG,"onCreate ..before socket connection...");
            mSocket= IO.socket("your server ip:8080");// WIFI WHAT YOU CONNECTED
            Log.d(TAG,"onCreate ..After socket connection...");
            mSocket.connect();
            mSocket.emit("join",Nickname);
            //IO.socket("192.168.0.192:8080").connect().emit("join",Nickname);
        } catch (URISyntaxException e) {
            e.printStackTrace();
        }
        // Set your RecycleView..
        mMessageList=new ArrayList<>();
        mRecycleView=findViewById(R.id.messagelist);
        RecyclerView.LayoutManager mLayoutManager= new LinearLayoutManager(getApplicationContext());
        mRecycleView.setLayoutManager(mLayoutManager);
        mRecycleView.setItemAnimator(new DefaultItemAnimator());

        // Button Connection...
        sendButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.d(TAG,"Send button clicked...");
                if(!messageText.getText().toString().isEmpty()){
                    mSocket.emit("messagedetection",Nickname,messageText.getText().toString());
                    messageText.setText(" ");
                }
                else if(messageText.getText().toString().isEmpty()){
                    Toast.makeText(ChatBoxActivity.this, "Please Enter your Message..",
                            Toast.LENGTH_LONG).show();
                }
            }
        });
           // Implementing socket Listener...
        mSocket.on("userjoinedthechat", new Emitter.Listener() {
            @Override
            public void call(final Object... args) {
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        String data=(String) args[0];
                        Toast.makeText(ChatBoxActivity.this,data,Toast.LENGTH_SHORT).show();
                    }
                });
            }
        });

        mSocket.on("userdisconnect", new Emitter.Listener() {
            @Override
            public void call(final Object... args) {
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        String data=(String) args[0];
                        Toast.makeText(ChatBoxActivity.this,data,Toast.LENGTH_SHORT).show();
                    }
                });
            }
        });

        // Message Sending ..
        mSocket.on("message", new Emitter.Listener() {
            @Override
            public void call(final Object... args) {
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        JSONObject data=(JSONObject) args[0];
                        try {
                            String Nickname=data.getString("senderNickname");
                            String message=data.getString("message");

                            Message msgInstance;
                            msgInstance=new Message(Nickname,message);
                            mMessageList.add(msgInstance);
                            mChatBoxAdapter=new ChatBoxAdapter(mMessageList);
                            mChatBoxAdapter.notifyDataSetChanged();
                            mRecycleView.setAdapter(mChatBoxAdapter);
                        } catch (JSONException e) {
                            e.printStackTrace();
                        }
                    }
                });
            }
        });


    }

}
