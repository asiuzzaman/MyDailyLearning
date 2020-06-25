#include<bits/stdc++.h>
using namespace std;
#define HASHMAX 50000 

typedef struct nodeStruct{
    char address[40];
    int age;

    struct nodeStruct * next;
}NODE;

NODE *hashTable[HASHMAX];

void init(){
    int i;
    for(i=0;i<HASHMAX;i++) hashTable[i]=NULL;
}
int Len(char str[]){

    int cnt=0;
    for(int i=0;str[i];i++){
        cnt++;
    }
    return cnt;
}

NODE * createNode(char addr[],int age){
    NODE * newNode=(NODE*) malloc(sizeof(NODE));
    int len= Len(addr);
    for(int i=0;i<len;i++){
        newNode->address[i]=addr[i];
    }
    newNode->age=age;
    newNode->next=NULL;
    return newNode;
}

/// Will be Improved this hashFunction later...
int hashFun(char key[]){
    int len=Len(key);
    int sum=0;
    for(int i=0;i<len;i++){
        sum+=key[i];
        cout<<key[i]<<endl;
    }
    cout<<"Sum of keys: "<<sum<<endl;
    int temp=sum%HASHMAX;
    cout<<"TEMP"<<temp<<endl;
    return temp;
}

void addPatient(char id[],char address[],int age){
    int index=hashFun(id);
    NODE * newNode=createNode(address,age);
   // newNode->next=hashTable[index];
    hashTable[index]=newNode;
}

void remove(char id[]){
    int index=hashFun(id);
    hashTable[index]=NULL;
    
}
// If it has unique key no need to chaining ....
void search(char id[]){
    int index=hashFun(id);
    NODE * curNode=hashTable[index];

    if(curNode){
        cout<<curNode->age<<endl;
    }else {
        cout<<"NOT Found"<<endl;
    }
    /*
    //if not chaining you can avoid this part
    int flag=0;
    while(curNode!=NULL){

            flag=1;
            for(int i=0;address[i];i++){
                if(curNode->address[i]!=address[i]) {
                    flag=0;
                    cout<<"First te pailam na"<<endl;
                    break;
                }
            }
            if(flag) break;
            
             curNode=curNode->next;
    }
    if(flag) cout<<"String Found"<<endl;
    else cout<<"NOT Found"<<endl;
*/
}

int main(){
    init();
    char key[10]={'a','b','c','d'};
    char add[10]={'D','h','a','k','a'};
    int age=25;
    
    char key1[10]={'a','b','c','d','e'};
    char add1[20]={'B','a','n','g','l','a','d','e','s','h'};
    int age1=45;

    char key2[10]={'a','b','c','d','e','f'};
    char add2[20]={'C','h','i','t','t','a','g','o','n','g'};
    int age2=85;


    addPatient(key,add,age);
    addPatient(key1,add1,age1);
    addPatient(key2,add2,age2);

    remove(key2);

    //char searchKey[10]={'a','b','c','d','e','f'};
    search(key2);
}