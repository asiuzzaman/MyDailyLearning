#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MX 6
int Parent[MX];

int find(int i){
   if(Parent[i]==i) return i;
   else {
      int x=find(Parent[i]);
      return x;
   }
}

void Union(int i,int j){
  int a=find(i);
  int b=find(j);

   Parent[a]=b;
}

int main(){
   for(int i=0;i<MX;i++){
      Parent[i]=i;
   }
   Union(1,0);
   Union(0,2);
   Union(3,4);
   Union(1,4);
   for(int i=0;i<MX;i++){
      printf("%d ",Parent[i]);
   }
   printf("\n");
   int x=find(5);
   printf("Find: %d \n",x);

}