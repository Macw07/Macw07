#include <iostream>
#include <algorithm>
using namespace std;

int v, n, volume[35];
int dp[35][20005];

int main(){
    cin >> v >> n;
    for (int i=1; i<=n; i++){
        cin >> volume[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=0; j<=v; j++){
            if (j >= volume[i]){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-volume[i]]+volume[i]);
            } else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << v-dp[n][v] << endl;
    return 0;
}