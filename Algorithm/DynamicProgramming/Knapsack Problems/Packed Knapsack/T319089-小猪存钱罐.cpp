#include <iostream>
#include <cstring>
using namespace std;

int k, n;
int c[3005], v[3005];
int dp[3005];

int main(){
    cin >> k >> n;
    for (int i=1; i<=n; i++){
        cin >> c[i] >> v[i];
    }
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    for (int i=1; i<=n; i++){
        for (int j=0; j<=k; j++){
            if (j >= v[i] && dp[j-v[i]] >= 0){
                dp[j] = max(dp[j], dp[j-v[i]]+c[i]);
            }
        }
    }
    if (dp[k] >= 0){
        cout << dp[k] << endl;
    } else{
        cout << "NO" << endl;
    }
    return 0;
}