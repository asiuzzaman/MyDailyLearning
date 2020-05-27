#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MXN 100005
#define MOD 1000000007
// First and last occurance of an element


int BS(int Arr[],int n,int x){
  int low=0,hi=n-1,result=-1;

      while(low<=hi){
        int mid=(hi-low)/2+low;
        if(Arr[mid]==x){
           result=mid;
           hi=mid-1;
        }
       else if(Arr[mid]>x){
          hi=mid-1; // Go search for lower......indices...
       }
       else {
         low=mid+1;
       }
   }
   cout<<"Check"<<endl;
   return result;
}


int BSHI(int Arr[],int n,int x){
  int hi=n-1,low=0,result=-1;

  while(low<=hi){
    int mid=(hi-low)/2+low;
    if(Arr[mid]==x){
      /// NOt giving return instead save the value
      result=mid;
      low=mid+1;
    }
   else if(x>Arr[mid]) low=mid+1;
    else hi=mid-1;
  }  // End of the while LOOP
  return result;

}

int main() {
  int Arr[]={1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 7, 7, 8, 8, 8, 8, 9, 9, 10, 10, 10 };
  int N=sizeof(Arr)/sizeof(Arr[0]);
  int x=1;
  cout<<"-----------"<<endl;
  int first=BS(Arr,N,x);
  int last=BSHI(Arr,N,x);
  cout<<last-first+1<<endl;

}