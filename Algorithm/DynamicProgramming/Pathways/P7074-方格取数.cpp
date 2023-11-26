#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
long long dp[1005][1005];

long long max(long long a, long long b){
    if (a > b) return a;
    return b;
}

int main(){
    cin >> n >> m;
    memset(dp, -0x7f, sizeof dp);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> dp[i][j];
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            dp[i][j] += max(dp[i-1][j], max(dp[i+1][j], dp[i][j-1]));
        }   
    }
    cout << dp[n][m] << endl;
    return 0;
}