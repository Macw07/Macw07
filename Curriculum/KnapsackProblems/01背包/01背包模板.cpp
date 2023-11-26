#include <iostream>
#include <algorithm>
using namespace std;

int n, m;  // n表示n件物品，m表示背包的容量
int volume[105], value[105];
int dp[105][1005];

/*
18 7
3 60
1 0
4 5
1 3 
2 4
5 30
16 23
*/

int main(){
    cin >> m >> n;
    for (int i=1; i<=n; i++){
        cin >> volume[i] >> value[i];
    }
    for (int i=1; i<=n; i++){  // 表示当前的物品
        for (int j=0; j<=m; j++){  // 表示当前的容量
            if (j-volume[i] >= 0){  // 还能装
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-volume[i]]+value[i]);
            } else{  // 装不下
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}