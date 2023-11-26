#include <iostream>
#include <algorithm>
using namespace std;

int v[105], c[105], num[105], n, w;
int dp[105][105];

int main(){
    cin >> n >> w;
    for (int i=1; i<=n; i++){
        cin >> c[i] >> v[i] >> num[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=0; j<=w; j++){
            for (int k=0; k<=num[i]; k++){
                if (j >= k*v[i]){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-k*v[i]]+k*c[i]);
                }
            }
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}