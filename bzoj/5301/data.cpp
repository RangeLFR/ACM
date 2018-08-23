#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
int random(int n){
  return (long long)rand()*(long long)rand()%n;
}
int main(){
  int n=random(10)+1,m=random(10)+1;
  int k=random(21);
  int tot=0;
  for (int i=1;i<=n;i++)printf("%d ",random(51));
  while (tot<m){
    int l=random(n)+1,r=random(n)+1;
    if (l<=r){
      tot++;
      printf("%d %d\n",l,r);
    }
  }
}
