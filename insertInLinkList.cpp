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
    Node * newNode=(Node*) malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=root;
    return newNode;
}

int main(){
   printf("Program Initialize....\n");
   Node * Root=NULL;
   // insert 4 node...
   for(int i=0;i<4;i++){
       int data;
       scanf("%d",&data);
       Root=insertFirst(Root,data);

   }
   printList(Root);
}