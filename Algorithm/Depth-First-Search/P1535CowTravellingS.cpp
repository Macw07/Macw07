#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int n, m, k;
char arr[105][105];
// 一个点可以走好几次，所以就不需要设置vis数组记录是否走过了
int memo[105][105][20];
int s1, s2, e1, e2;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dfs(int x, int y, int times){
    if (memo[x][y][times] != -1) return memo[x][y][times];
    if (abs(x-e1)+abs(y-e2) > k-times) return memo[x][y][times] = 0;

    if (times == k){
        if (x == e1 && y == e2) return memo[x][y][times] = 1;
        return memo[x][y][times] = 0;
    }
    int ans = 0;
    for (int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 1 || cy < 1 || cx > n || cy > m || arr[cx][cy] == '*') continue;
        // 开始走
        ans += dfs(cx, cy, times+1);
    }
    return memo[x][y][times] = ans;
}

int main(){
    memset(memo, -1, sizeof memo);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    cin >> s1 >> s2 >> e1 >> e2;
    cout << dfs(s1, s2, 0) << endl;
    return 0;
}