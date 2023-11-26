#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int dp[30005];
int v[35], p[35];

int main(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        cin >> v[i] >> p[i];
        p[i] = p[i] * v[i];
    }
    // 典型的01背包问题
    for (int i=1; i<=m; i++){
        for (int j=n; j>=v[i]; j--){
            dp[j] = max(dp[j], dp[j-v[i]]+p[i]);
        }
    }
    cout << dp[n] << endl;
    return 0;       
}