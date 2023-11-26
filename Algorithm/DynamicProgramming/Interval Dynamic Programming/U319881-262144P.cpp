#include <iostream>
using namespace std;

typedef long long ll;

ll n, ans; 
ll dp[100][262500];  // 所以f[i][j]表示在数列上以j为起点，能合成数i的区间长度。

int main(){
    cin >> n;
    for (ll i=1; i<=n; i++){
        ll t; cin >> t;
        dp[t][i] = 1;  // 以i为起点，能合成数字t的区间长度。
    }
    // 58可以通过 40 + log(262144) 得出。
    for (ll i=2; i<=58; i++){
        for (ll j=1; j<=n; j++){
            if (!dp[i][j]){
                if (dp[i-1][j] && dp[i-1][j+dp[i-1][j]])
                dp[i][j] = dp[i-1][j] + dp[i-1][j+dp[i-1][j]];
            }
            if (dp[i][j]) ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}