#include <iostream>
using namespace std;

long long dp[10000005], timee[10000005], value[10000005];

int main(){
    int m, n;
    cin >> m >> n;
    for (int i=1; i<=n; i++){
        cin >> timee[i] >> value[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=timee[i]; j<=m; j++){
            dp[j] = max(dp[j], dp[j-timee[i]]+value[i]);
        }
    }
    cout << dp[m];
    return 0;
}