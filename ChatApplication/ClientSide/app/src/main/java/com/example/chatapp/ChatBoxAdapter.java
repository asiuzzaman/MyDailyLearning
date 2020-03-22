package com.example.chatapp;

import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

public class ChatBoxAdapter extends RecyclerView.Adapter<ChatBoxAdapter.MyViewHolder> {
    private List<Message>MessageList;
    private static final String TAG="MYChatChatBoxAdapter";
    @NonNull
    @Override
    public ChatBoxAdapter.MyViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View itemView= LayoutInflater.from(parent.getContext()).inflate(R.layout.activity_chat_box,parent,false);
        return new ChatBoxAdapter.MyViewHolder(itemView);
    }

    @Override
    public void onBindViewHolder(final ChatBoxAdapter.MyViewHolder holder, int position) {
        final Message m=MessageList.get(position);
        holder.nickname.setText(m.getNickName()+" : ");
        holder.message.setText(m.getMessage());
    }

    @Override
    public int getItemCount() {
        return MessageList.size();
    }

    public class MyViewHolder extends RecyclerView.ViewHolder{
        public TextView nickname;
        public TextView message;
        public MyViewHolder(View view){
            super(view);
            nickname=view.findViewById(R.id.item_nickname);
            message=view.findViewById(R.id.item_message);
        }
    }
    public ChatBoxAdapter(List<Message> messageList){
        Log.d(TAG,"Enter ChatBox Adapter..");
        this.MessageList=messageList;
    }
}
