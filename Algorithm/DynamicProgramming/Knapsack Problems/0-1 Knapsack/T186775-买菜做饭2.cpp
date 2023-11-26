#include <iostream>
using namespace std;

int k, n, m, ans;
int c[3005], v[3005], w[3005], p[3005];
int dp[3005];

int main(){
    cin >> k >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> c[i] >> v[i];
    }
    for (int i=1; i<=m; i++){
        cin >> w[i] >> p[i];
    }
    for (int i=1; i<=m; i++){
        for (int j=k; j>=w[i]; j--){
            dp[j] = max(dp[j], dp[j-w[i]]+p[i]);
        }
    }
    for (int i=1; i<=n; i++){
        if(c[i] <= k){
            ans = max(ans, dp[k-c[i]]+v[i]);
        }
    }
    cout << ans << endl;
    return 0;
}