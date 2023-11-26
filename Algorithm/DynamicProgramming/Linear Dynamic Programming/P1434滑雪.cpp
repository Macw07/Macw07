#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans=0;
int dp[205][205];
int s[205][205];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int dfs(int x, int y){
    if (s[x][y]) return s[x][y];  // 记忆化搜索,已经搜索到了,因此不需要再次搜索了.
    s[x][y] = 1;  // 包括自身
    // 向四个方向进行搜索
    for (int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx > 0 && cy > 0 && cx <= n && cy <= m && dp[x][y]>dp[cx][cy]){
            dfs(cx, cy);
            s[x][y] = max(s[x][y], s[cx][cy]+1);
        }
    }
    return s[x][y];
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> dp[i][j];
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << endl;
    return 0;
}