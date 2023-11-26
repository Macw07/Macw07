#include <iostream>
#include <algorithm>
using namespace std;

int n, w;
int v[105], c[105], dp[105][105];

int main(){
    cin >> n >> w;
    for (int i=1; i<=n; i++){
        cin >> v[i] >> c[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=0; j<=w; j++){
            if (j >= v[i]){
                dp[i][j] = max(dp[i-1][j], dp[i][j-v[i]]+c[i]);
            } else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}