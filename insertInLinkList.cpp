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


int main(){
   printf("Program Initialize....\n");
   Node * Root=creatNode(5);
   printf("%d \n",Root->data);

}