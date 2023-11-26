#include <iostream>
using namespace std;

int n, w;
int c[505], v[505];
int dp[505][505];

int main(){
    cin >> n >> w;
    for (int i=1; i<=n; i++){
        cin >> c[i] >> v[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=0; j<=w; j++){
            if (j >= v[i]){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i]]+c[i]);
            } else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}