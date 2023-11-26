// #include <iostream>
// #include <algorithm>
// #include <cmath>
// using namespace std;

// // 备注：第一次竟然只有50分，有点伤心。

// int n, sum=0, ans=0x7f7f7f, m=0x7f7f7f;
// int dp[105];
// int v[105];

// int main(){
//     cin >> n;
//     for (int i=1; i<=n; i++){
//         cin >> v[i];
//         sum += v[i];
//         m = min(v[i], m);
//     }
//     ans = sum-m-m;
//     // 01 背包分配财产
//     for (int i=1; i<=n; i++){
//         for (int j=sum; j>=v[i]; j--){
//             dp[j] = max(dp[j], dp[j-v[i]]+v[i]);
//             ans = min(ans, abs(abs(sum-dp[j])-dp[j]));
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }

#include <iostream>
#include <algorithm>
using namespace std;

int n, sum = 0;;
int value[105];
int dp[105][10005];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> value[i];
        sum += value[i];  // sum 是最大的价值
    }

    for (int i=1; i<=n; i++){
        for (int j=0; j<=sum/2; j++){
            if (j-value[i] >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-value[i]]+value[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << sum-2*dp[n][sum/2] << endl;
    return 0;
}