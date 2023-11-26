#include <iostream>
using namespace std;

int dp[1005],w[105],v[105];

int main(){
    int t, m;
    cin >> t >> m;
    for (int i=1; i<=m; i++){
        cin >> w[i] >> v[i];
    }
    // 动态规划
    for (int i=1; i<=m; i++){
        for (int j=t; j>=1; j--){
            if (j >= w[i]) {
                dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
            }
        }
    }
    cout << dp[t];
    return 0;
}