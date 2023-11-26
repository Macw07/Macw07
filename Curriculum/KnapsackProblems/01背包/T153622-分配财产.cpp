#include <iostream>
#include <algorithm>
using namespace std;

int n, sum=0, m;
int value[1005];
int dp[1005][1005];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> value[i];
        sum += value[i];
    }
    m = sum / 2;
    for (int i=1; i<=n; i++){
        for (int j=0; j<=m; j++){
            if (j >= value[i]){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-value[i]]+value[i]);
            } else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << sum-2*dp[n][m] << endl;
    return 0;
}