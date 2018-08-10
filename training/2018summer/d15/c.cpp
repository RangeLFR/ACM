/*QYitong1smyBOSS*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#define ll long long
using namespace std;
char s[15005], s1[15005], s2[15005];
int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n/2; i++) {
        s1[i] = s[i];
        s2[i] = s[i+n/2];
    }
    int sum = 0;
    for (int i = 0; i < n/2; i++) sum += s1[i] - 'A';
    for (int i = 0; i < n/2; i++) {
        int tmp = sum;
        s1[i] = (s1[i]-'A'+tmp)%26 + 'A';
    }
    sum = 0;
    for (int i = 0; i < n/2; i++) sum += s2[i] - 'A';
    for (int i = 0; i < n/2; i++) {
        int tmp = sum;
        s2[i] = (s2[i]-'A'+tmp)%26 + 'A';
    }
    for (int i = 0; i < n/2; i++) {
        s1[i] = (s1[i]-'A'+s2[i]-'A')%26 + 'A';
    }
    printf("%s\n", s1);
}