#include<bits/stdc++.h>
using namespace std;

#define TABLESIZE 10

typedef struct nodeStruct{
    int index;
    struct nodeStruct * next;
}Node;

Node * hashTable[TABLESIZE];

Node * createNode(int index){
    Node * newNode=(Node*) malloc(sizeof(Node));
    newNode->index=index;
    newNode->next=NULL;
    return newNode;
}

void insert(int * nums,int i){
    int hashCode;
    if(nums>=0){
        hashCode=nums[i]%TABLESIZE;
    }else{
        hashCode=(-nums[i])%TABLESIZE;
    }
    Node * newNode=createNode(i);
    newNode->next=hashTable[hashCode];
    hashTable[hashCode]=newNode;
}

int* twoSum(int *nums,int numsSize,int target,int *returnSize){
    for(int i=0;i<TABLESIZE;i++){
        hashTable[i]=NULL;
    }

    for(int i=0;i<numsSize;i++){
        insert(nums,i);
    }

    int *result=(int*)malloc(sizeof(int)*2);
    *returnSize=2;

    for(int i=0;i<numsSize;i++){
        int key=target-nums[i];
        int hashCode;
        if(key>=0){
            hashCode=key%TABLESIZE;
        }else{
            hashCode=-key%TABLESIZE;
        }
        Node *curNode=hashTable[hashCode];

        while(curNode!=NULL){
            if(nums[curNode->index]==key && i!=curNode->index){
                result[0]=i;
                result[1]=curNode->index;
                return result;
            }
            curNode=curNode->next;
        }
    }
  
    return result;
}
int main(){
    int  num[]={2,7,11,15};
    int *p=num;
    int numSize=4;
    int target=18;
    int two=2;
    int *res=twoSum(p,numSize,target,&two);
    cout<<res[0]<<" "<<res[1]<<endl;
  
}
