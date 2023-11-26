#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int t, n, m, ans;
int arr[15][15];
int vis[15][15];
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

void dfs(int x, int y, int sum){
    ans = max(ans, sum);

    if (y > m) y = 1, x += 1;
    if (x > n) return ;

    if (!vis[x][y]){
        vis[x][y] += 1;
        for (int i=0; i<8; i++) vis[x + dx[i]][y + dy[i]] += 1;
        dfs(x, y+1, sum + arr[x][y]);
        vis[x][y] -= 1;
        for (int i=0; i<8; i++) vis[x + dx[i]][y + dy[i]] -= 1;
    }
    dfs(x, y+1, sum);
    return ;
};

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                cin >> arr[i][j];
                memset(vis, 0, sizeof vis);
            }
        }
        ans = 0;
        dfs(1, 1, 0);
        cout << ans << endl;
    }
    return 0;
}