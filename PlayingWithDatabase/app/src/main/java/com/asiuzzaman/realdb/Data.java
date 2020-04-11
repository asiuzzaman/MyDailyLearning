package com.asiuzzaman.realdb;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;
import android.widget.Toast;

import java.sql.SQLException;

public class Data extends AppCompatActivity {

    private TextView tvData;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_data);
        tvData=findViewById(R.id.DataFromDatabaseId);

            ContactsDB db = new ContactsDB(this);
            db.open();
            tvData.setText(db.getData());
            db.close();
           // Toast.makeText(this,e.getMessage(),Toast.LENGTH_SHORT).show();

    }
}
