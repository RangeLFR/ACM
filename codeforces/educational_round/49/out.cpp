#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
  printf("250000\n");
  for (int i=1;i<=250000;i++){
    printf("4\n1 1 %d %d\n",min(i,10000),min(i,10000));
  }
}
