#include <iostream>
using namespace std;

int n, m, ans, mod = 100000007;
int arr[105][105];
int dp[105][1050];

int main(){
    // freopen("Data/testcase25.in", "r", stdin);
    // freopen("Data/testcase25.out", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    dp[0][0] = 1;
    for (int i=1; i<=n; i++){
        for (int j=0; j<(1<<m); j++){
            // 排除两条鱼在一起的情况。
            if ((j & (j << 1)) >= 1) continue;
            // 如果这一组合会被设备给阻挡，那么也过滤掉。
            bool flag = true;
            for (int k=1; k<=m; k++){
                if (arr[i][k] == 0){
                    if (j & (1 << (k-1))){
                        flag = false;
                    }
                }
            }
            if (!flag) continue;

            for (int k=0; k<(1<<m); k++){
                if ((k & (k << 1)) >= 1) continue;
                if ((k & j) >= 1) continue;
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= mod;
            }
        }
    }
    for (int j=0; j<(1<<m); j++){
        ans += dp[n][j];
        ans %= mod;
    }
    cout << ans-1 << endl;
    return 0;
}