#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int w[35], c[35], p[35];
int dp[1005];

int main(){
    cin >> m >> n;
    for (int i=1; i<=n; i++){
        cin >> w[i] >> c[i] >> p[i];
    }
    for (int i=1; i<=n; i++){
        if (p[i] == 0){
            // 完全背包
            for (int j=w[i]; j<=m; j++){
                dp[j] = max(dp[j], dp[j-w[i]]+c[i]);
            }
            continue;
        } 
        for (int j=m; j>=0; j--){
            for (int k=0; k<=p[i]; k++){
                if (j >= k*w[i]) dp[j] = max(dp[j], dp[j-k*w[i]]+k*c[i]);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}