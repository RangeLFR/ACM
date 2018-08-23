#include <stdio.h>
#define mod 100003
#define ll long long
ll ksm(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    b >>= 1;
    a = (a * a) % mod;
  }
  return res;
}
int main() {
  ll n, m;
  scanf("%lld%lld", &m, &n);
  printf("%lld\n", (ksm(m, n)-(m*ksm(m-1, n-1))%mod+mod)%mod);
}
