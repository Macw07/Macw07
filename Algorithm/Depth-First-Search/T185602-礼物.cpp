#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans;
int arr[105][105];
int dp[105][105];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

void dfs(int x, int y, int sum){
    if (x > n || y > n) return ;
    if (x == n && y == m) {
        ans = max(ans, sum);
        return ;
    }

    dfs(x, y+1, sum + arr[x][y+1]);
    dfs(x+1, y, sum + arr[x+1][y]);
    return ;
}

void dp_(){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            dp[i][j] += max(dp[i-1][j], dp[i][j-1]);
            // cout << dp[i][j] << endl;
        }
    }
    return ;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
            dp[i][j] = arr[i][j];
        }
    }
    // dfs(1, 1, arr[1][1]);
    // cout << ans << endl;
    dp_();
    cout << dp[n][m] << endl;
    return 0;
}