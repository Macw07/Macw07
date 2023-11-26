#include <iostream>
#include <algorithm>
using namespace std;

int ans = 0;
int n, m, x, y;
int dp[1005][1005];

int main(){
    cin >> n >> m >> x >> y;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> dp[i][j];
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    for (int i=0; i<=n-x; i++){
        for (int j=0; j<=m-y; j++){
            int area = dp[i+x][j+y] - dp[i][j+y] - dp[i+x][j] + dp[i][j];
            ans = max(area, ans);
        }
    }
    cout << ans << endl;
    return 0;
}