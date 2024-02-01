#include <iostream>
using namespace std;

const int MOD = 1e7;
int n, m, ans;
int arr[205][205];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

// 深度优先搜索 Brute Force
void dfs(int x, int y){
    if (x > n) {
        ans += 1;
        ans %= MOD;
        return ;
    }
    if (y > m){
        dfs(x+1, 1);
        return ;
    }
    if (arr[x][y] == 0){
        dfs(x, y+1);
        return ;
    }
    // 不放鱼
    dfs(x, y+1);

    // 放鱼
    for (int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 1 || cy < 1 || cx > n || cy > m) continue;
        if (arr[cx][cy] == 2) return ;
    }
    arr[x][y] = 2;
    dfs(x, y+1);
    arr[x][y] = 1;
    return ;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    // dfs 暴力
    dfs(1, 1);
    cout << ans-1 << endl;
    return 0;
}