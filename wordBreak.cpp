#include<stdio.h>
#include<malloc.h>
#include<iostream>
#include<string>
#include<stdbool.h>
using namespace std;

typedef struct nodeStruct{
  nodeStruct * next[26];
  bool endMark;
}Node;

Node * createNode(){
  Node * newNode=(Node*)malloc(sizeof(Node));
  newNode->endMark=false;
  for(int i=0;i<26;i++){
    newNode->next[i]=NULL;
  }
  return newNode;
}

void insert(Node * root, string word){
    Node * cur=root;
    for(int i=0;word[i];i++){
      int index=word[i]-'a';
      if(cur->next[index]==NULL) cur->next[index]=createNode();
      cur=cur->next[index];
    }
    cur->endMark=true;
}

bool search(Node * root,string word){
  Node * cur=root;
  for(int i=0;word[i];i++){
    int index=word[i]-'a';
    if(cur->next[index]==NULL) return false;
    cur=cur->next[index];
  }
  return (cur->endMark && cur);
}

bool wordBreak(Node * root, string str){
  int size=str.size();

  if(size==0) return true;

  for(int i=1;i<=size;i++){
    string temp=str.substr(0,i);
    string temp1=str.substr(i,size-i);
    if(search(root,temp ) && ( wordBreak(root,temp1)))  return true;
  }  
  return false;
}


int main(){
  string dictionary[]={
    "mobile","samsung","sam", 
    "sung","ma\n","mango", 
    "icecream","and","go","i", 
  "like","ice","cream"
  };
   Node * root=createNode();
   int n = sizeof(dictionary)/sizeof(dictionary[0]); 
   for(int i=0;i<n;i++){
     insert(root,dictionary[i]);
   }
   wordBreak(root,"ilikesamsung")? cout <<"Yes\n": cout << "No\n"; 

}