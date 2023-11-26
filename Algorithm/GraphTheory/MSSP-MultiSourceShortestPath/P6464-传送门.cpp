#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int t1, t2, w;
int n, m, ans = 0x7f7f7f7f;
int dp[105][105];
int dp2[105][105];

void back(){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            dp2[i][j] = dp[i][j];
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    memset(dp, -1, sizeof dp);
    while(m--){
        scanf("%d %d %d", &t1, &t2, &w);
        dp[t1][t2] = dp[t2][t1] = w;
    }

    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if(dp[i][k] == -1 || dp[k][j] == -1) continue;
                if (dp[i][j] == -1 || dp[i][k] + dp[k][j] < dp[i][j])
                dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            back();
            dp2[i][j] = dp2[j][i] = 0;  // 建立传送门
            // 更新通过i和j两个点所中转的所有点的值。不需要跑一整遍的floyd。
            for(int x=1; x<=n; x++){
                for (int y=1; y<=n; y++){
                    if (dp2[x][y] == -1 || dp2[x][i] + dp2[i][y] < dp2[x][y])
                    dp2[x][y] = dp2[x][i] + dp2[i][y];
                }
            }
            for(int x=1; x<=n; x++){
                for (int y=1; y<=n; y++){
                    if (dp2[x][y] == -1 || dp2[x][j] + dp2[j][y] < dp2[x][y])
                    dp2[x][y] = dp2[x][j] + dp2[j][y];
                }
            }
            int sum = 0;
            for (int x=1; x<=n; x++){
                for(int y=1; y<x; y++){
                    sum += dp2[x][y];  // 答案累加
                }
            }
            ans = min(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}