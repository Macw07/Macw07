#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int p[505], h[505], c[505];
int dp[505][105];

int main(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        cin >> h[i] >> p[i] >> c[i];
    }
    for (int i=1; i<=m; i++){
        for (int j=0; j<=n; j++){
            for (int k=0; k<=c[i]; k++){
                if (j >= k*h[i]){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-k*h[i]]+k*p[i]);
                }
            }
        }
    }
    cout << dp[m][n] << endl;
    return 0;
}