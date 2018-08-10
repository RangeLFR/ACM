#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main() {
  int T; cin >> T;
  while (T--) {
    cin >> n;
    if (n % 2 == 1) puts("Balanced");
    else puts("Bad");
  }
}