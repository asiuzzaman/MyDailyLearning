#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MXN 123456

struct info{
    int prop,sum;
}Tree[100*3];

void update(int node,int b,int e,int i,int j,int x){
    // very crucital contion...
    if(i>e || j<b) return;   // out of range..

    if(b>=i  && e<=j) {   // you have to update here...
        Tree[node].sum=(e-b+1)*x;   // As the number of node is e-b+1 , that's why e-b+1 times add this
        Tree[node].prop+=x;  /// Add x to the downed node...
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,x);
    update(node,mid+1,right,i,j,x);
    Tree[node].sum=Tree[left].sum+Tree[right].sum+(e-b+1)*Tree[node].prop;

}

int query(int node,int b,int e,int i,int j,int carry=0){
    if(i>e || j<b) return 0;

    if(b>=i && e<=j) {
        int ret=Tree[node].sum=carry* (e-b+1);
        return ret;
    }

    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    int p=query(left,b,mid,i,j,carry+Tree[node].prop);
    int q=query(right,mid+1,e,i,j,carry+Tree[node].prop);
    int res=p+q;
    return res;
}

int main(){
    
}