package com.asiuzzaman.playground;

import androidx.appcompat.app.AppCompatActivity;

import android.database.Cursor;
import android.os.Bundle;
import android.view.View;
import android.widget.ScrollView;
import android.widget.TextView;
import android.widget.Toast;

import com.asiuzzaman.playground.database.MyDataSource;
import com.asiuzzaman.playground.utilities.ActivityHelper;

public class MainActivity extends AppCompatActivity {
    private ScrollView mScrollView;
    private TextView mLog,mSearch;
    private MyDataSource myDataSource;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mScrollView=findViewById(R.id.scrollLog);
        mLog=findViewById(R.id.tvLog);
        mLog.setText("");
        mSearch=findViewById(R.id.searchText);
        myDataSource=new MyDataSource(this);
        myDataSource.initData();
    }
    public void onRunBtnClick(View v){
       searchDatabase(v);

    }
    public void onClearBtnClick(View v){
        mLog.setText("");
        mScrollView.scrollTo(0,mScrollView.getBottom());
    }
    public void displayMessage(String message){
        ActivityHelper.log(this,mLog,message,true);
        mScrollView.scrollTo(0,mScrollView.getBottom());
    }

    public void searchDatabase(View view) {

        String searchString = mSearch.getText().toString();

        if (searchString.length() == 0) {
            Toast.makeText(MainActivity.this, "Enter an integer between 1 and 100",
                    Toast.LENGTH_SHORT).show();
            return;
        }

        int indexValue = new Integer(searchString);

        Cursor cursor = myDataSource.selectRecord(indexValue);
        if (cursor.moveToNext()) {
            String name = cursor.getString(cursor.getColumnIndex(MyDataSource.PERSON_NAME));
            Toast.makeText(MainActivity.this, "You found " + name, Toast.LENGTH_SHORT).show();
        } else {
            Toast.makeText(MainActivity.this, "Person not found", Toast.LENGTH_SHORT).show();
        }

    }
}
