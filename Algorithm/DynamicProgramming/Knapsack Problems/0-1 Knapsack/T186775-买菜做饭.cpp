#include <iostream>
#include <algorithm>
using namespace std;

int k, n, m;
int c[5005], v[5005];
int dp[5005];

int main(){
    cin >> k >> n >> m;
    for (int i=1; i<=n+m; i++){
        cin >> c[i] >> v[i];
    }
    // 先买蔬菜
    for (int i=n+1; i<=n+m; i++){
        for (int j=k; j>=c[i]; j--){
            dp[j] = max(dp[j], dp[j-c[i]]+v[i]);
        }
    }
    // 再买一只螃蟹
    int ans = 0;
    for (int i=1; i<=n; i++){
        // 螃蟹只能买一只
        if (k - c[i] >= 0){
            ans = max(ans, dp[k-c[i]]+v[i]);
        }
    }
    cout << ans << endl;
    return 0;
}