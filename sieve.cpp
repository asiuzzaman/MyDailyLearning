#include<bits/stdc++.h>
using namespace std;

vector<int>prime;
void sieve(int n) 
{   
    bool vis[n];
    for(int i=0;i<=n;i++){
        vis[i]=false;
    } 
    int sq=sqrt(n);
    for(int i=3;i<=sq;i+=2){
        if(vis[i]==false){
            for(int j=i*i;j<n;j+=2*i){
                vis[j]=true;
            }
        }
    }
    prime.push_back(2);
    for(int i=3;i<n;i+=2){
        if(!vis[i]) prime.push_back(i);
    }
} 

int main(){
   sieve(1000000);
}
