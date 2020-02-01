#include<iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
};

Node * creatNode(int data){
    Node * newNode=(Node*) malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;

    return newNode;
}

void printList(Node * root){
    while(root){
        printf("%d ",root->data);
        root=root->next;
    }
    printf("\n");
}
Node * insertFirst(Node * root,int data){
    Node * newNode=creatNode(data);
    newNode->next=root;
    return newNode;
}

Node * insertLast(Node * root,int data){
    Node * newNode=creatNode(data);
    if(root==NULL) return newNode;
    Node * temp=root;  // Just save the reference...
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return root;
}
int main(){
   printf("Program Initialize....\n");
   Node * Root=NULL;
   for(int i=0;i<5;i++){
   int data;
   scanf("%d",&data);
   Root=insertLast(Root,data);
   }
   printList(Root);
}