#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MXN 100005


int segment[1000];
int preprocess(int input[],int n){
    int current_segment=-1;
    int segmentSize=sqrt(n);
    cout<<"SegmentSize:"<<segmentSize<<endl;
    for(int i=0;i<n;i++){
        segment[i/segmentSize]+=input[i];
    }
    return segmentSize;
}

int query(int input[],int segmentSize,int l,int r){
    int sum=0;
    
    // Loop the first segment untill we 
    // rearch r or a starting index...
    while( l<r && l%segmentSize!=0){
        sum+=input[l];
        l++;
    }
    cout<<"value of L after first segment:"<<l<<endl;

    //Loop until we reach segment 
    // that contaion r

    while (l+segmentSize<=r)
    {
        sum+=segment[l/segmentSize];
        l+=segmentSize;
    }
    
    // Loop until we get R 
    while(l<=r){
        sum+=input[l];
        l++;
    }
    return sum;  

}

// Have to update the ith position with value v;

void update(int input[],int segmentSize,int i,int v){
    int segmentNo=i/segmentSize;
    segment[segmentNo]-=input[i];
    segment[segmentNo]+=v;
    input[i]=v;
}

int main() {
    
    int Arr[]={1,4,2,2,1,1,2,1,3,5,1,2,7}; 
    int N=13;
    int segmentSize=preprocess(Arr,N);
    for(int i=0;i<4;i++){
        cout<<segment[i]<<" ";
    }
    cout<<endl;
    int sqrtN=sqrt(N);
    cout<<"Query: "<<query(Arr,sqrtN,2,10)<<endl;
    update(Arr,sqrtN,5,10);
     cout<<"Query: "<<query(Arr,sqrtN,2,10)<<endl;
   
}