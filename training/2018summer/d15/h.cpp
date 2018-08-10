/*QYitong1smyBOSS*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
#define ll long long
using namespace std;
int n, m;
char s[105][105];
int vis[105][105];
int dx[] = {-1,1,0};
int ans;
int dy[] = {-1,1,0};
bool inside(int x, int y) {
    if (x >= 1 && x <= n && y >= 1 && y <= m) return true;
    return false;
}
void dfs(int x, int y) {
    vis[x][y] = ans;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 2 && j == 2) break;
            int nx = x + dx[i], ny = y + dy[j];
            if (inside(nx, ny) && s[nx][ny] == '#' && !vis[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", s[i]+1);
    ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '#' && !vis[i][j]) {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
}