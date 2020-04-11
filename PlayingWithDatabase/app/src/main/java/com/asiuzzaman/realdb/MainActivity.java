package com.asiuzzaman.realdb;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.database.SQLException;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    EditText etName,etCell;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        etName=findViewById(R.id.EditTextNameId);
        etCell=findViewById(R.id.EditTextCellId);
    }

    public void SubmitButtonId(View view){
        String name=etName.getText().toString().trim();
        String cell=etCell.getText().toString().trim();

        try {
            ContactsDB db = new ContactsDB(this);
            db.open();
            db.createEntry(name,cell);
            db.close();
            Toast.makeText(MainActivity.this,"Data Successfully Submit/Create/saved",Toast.LENGTH_SHORT).show();
            etName.setText("");
            etCell.setText("");
        }
        catch (SQLException e){
            Toast.makeText(this,e.getMessage(),Toast.LENGTH_SHORT).show();
        }
    }
    public void ShowButtonId(View view){
//        Intent intent=new Intent(MainActivity.this,Data.class);
//        startActivity(intent);
        startActivity(new Intent(MainActivity.this,Data.class));
    }

    public void EditButtonId(View view){
        try{
            ContactsDB db=new ContactsDB(this);
            db.open();
            db.updateEntry("1","Mohammad Asiuzzaman","01725955624");
            db.close();
            Toast.makeText(this,"Data Successfully Updated..",Toast.LENGTH_SHORT).show();
        }
        catch (SQLException e){
            Toast.makeText(this,e.getMessage(),Toast.LENGTH_SHORT).show();
        }
    }
    public void DeleteButtonId(View view){

        try {
            ContactsDB db=new ContactsDB(this);
            db.open();
            db.deleteEntry("1");
            db.close();
            Toast.makeText(this,"Data Successfully Deleted",Toast.LENGTH_SHORT).show();
        }
        catch (SQLException e){
            Toast.makeText(this,e.getMessage(),Toast.LENGTH_SHORT).show();
        }
    }
}
