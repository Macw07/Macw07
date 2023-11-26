#include <iostream>
using namespace std;

int n, m;
char arr[30][30];
long long dp[30][30];

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    dp[1][1] = 1;
    // 动态规划的递推做法。
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            // 往前找不同的。
            int count = 0;
            for (int k=1; k<i; k++){
                for (int l=1; l<j; l++){
                    if (arr[i][j] != arr[k][l]){
                        count += dp[k][l];
                    }
                }
            }
            dp[i][j] += count;
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}