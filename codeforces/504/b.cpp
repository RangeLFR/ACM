#include <bits/stdc++.h>
using namespace std;
long long n,k;
int main(){
  cin>>n>>k;
  
  if (k>n){
    long long a=k-n;
    if (a>n){
      cout<<0<<endl;
      return 0;
    }
    cout<<(n-a+1)/2<<endl;
  } else{
    long long a=k-1;
    cout<<(a)/2<<endl;
  }
}
