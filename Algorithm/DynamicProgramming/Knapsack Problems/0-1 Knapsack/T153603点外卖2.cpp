#include <iostream>
#include <algorithm>
using namespace std;

int n, m, sum = 0;
int ans = 0x7f7f7f7f;
int dp[2000];
int v[2000];

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> v[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=1005+m; j>=0; j--){
            if (j >= v[i]) dp[j] = max(dp[j], dp[j-v[i]]+v[i]);
            if (dp[j] >= m) ans = min(ans, dp[j]);
        }
    }
    cout << ans;
    return 0;
}