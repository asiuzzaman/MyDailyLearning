#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mxn=90000003;
vector<int>vec;
void sieve(){
static ll isPrime[mxn];
   for(int i=1;i<=mxn;i++){
      isPrime[i]=1;
   }
   isPrime[0]=isPrime[1]=0;

   for(int i=2;i*i<=mxn;i++){
      if(isPrime[i]){
         for(int j=i*i;j<=mxn;j+=i){
            isPrime[j]=0;
         }
      }
   }
   for(int i=2;i<mxn;i++){
      if(isPrime[i]==1) vec.push_back(i); 
   }
}                
int main() {

   sieve();
   ll store[mxn];
   
   int q;cin>>q;
   while(q--) {
   int qth;cin>>qth;
    cout<<vec[qth-1]<<endl;
   }
    
}