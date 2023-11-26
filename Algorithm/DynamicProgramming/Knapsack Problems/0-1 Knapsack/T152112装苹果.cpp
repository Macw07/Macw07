#include <iostream>
#include <algorithm>
using namespace std;

int dp[1100], weight[10000], v[10000];

int main(){
    int n, w;
    cin >> n >> w;
    for (int i=1; i<=n; i++){
        cin >> weight[i] >> v[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=w; j>=1; j--){
            if (j >= weight[i]){  // 注意：这里是j>=而不是dp[j]
                dp[j] = max(dp[j], dp[j-weight[i]]+v[i]);
            }
        }
    }
    cout << dp[w];
    return 0;
}