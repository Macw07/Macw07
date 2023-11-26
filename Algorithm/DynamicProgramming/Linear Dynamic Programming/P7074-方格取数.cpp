#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e3+15;

int n, m, ans = -0x7f7f7f7f;
int arr[MAXN][MAXN];
int vis[MAXN][MAXN];

int dx[] = {1, 0, -1};
int dy[] = {0, 1, 0};

void dfs(int x, int y, int sum){
    if (x == n && y == m){
        ans = max(sum, ans);
        return ;
    }

    for (int i=0; i<3; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx < 1 || cy < 1 || cx > n || cy > m || vis[cx][cy]) continue;
        // vis[cx][cy] = 1;
        dfs(cx, cy, sum + arr[cx][cy]);
        vis[cx][cy] = 0;
    }
    return ;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    vis[1][1] = 1;
    dfs(1, 1, arr[1][1]);
    cout << ans << endl;
    return 0;
}