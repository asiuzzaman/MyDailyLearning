#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mxn 100000

int Arr[mxn];
int Tree[mxn];  // Tree lenght must be 3x

void init(int node,int b,int e){
    if(b==e){
        Tree[node]=Arr[b];
        return;
    }
    int Left=2*node;
    int Right=2*node+1;
    int mid=(b+e)/2;
    init(Left,b,mid);
    init(Right,mid+1,e);
    int L=Tree[Left];

    int R=Tree[Right];
    Tree[node]=Tree[Left]+Tree[Right];
    int Res=Tree[node];
}

int quiry(int node,int b,int e,int i,int j){
    if(j<b || i>e) return 0;

    if(b>=i && e<=j) return Tree[node];

    int Left=(2*node);
    int Right=Left+1;
    int mid=(b+e)/2;
    int p=quiry(Left,b,mid,i,j);
    int q=quiry(Right,mid+1,e,i,j);
    int temp=p+q;
    return temp;
}
void update(int node,int b,int e,int pos,int newValue){
    if(pos<b || pos>e) return;
    if(b==e) {
        Tree[node]=newValue;
        return ;
    }
    int Left=2*node;
    int Right=Left+1;
    int mid=(b+e)/2;
    update(Left,b,mid,pos,newValue);
    update(Right,mid+1,e,pos,newValue);

    Tree[node]=Tree[Left]+Tree[Right];

}
int main() {
    int n=8;
    Arr[1]=1;Arr[2]=2;Arr[3]=3;Arr[4]=4;
    Arr[5]=5;Arr[6]=6;Arr[7]=7; Arr[8]=8;
    // 2, 4, -9, 8 , -1, 5, 2, 3
    init(1,1,n);

    cout<<quiry(1,1,n,3,6)<<endl;
    int pos=3,value=10;
    update(1,1,n,pos,value);
    cout<<quiry(1,1,n,3,6);
    cout<<endl;
}