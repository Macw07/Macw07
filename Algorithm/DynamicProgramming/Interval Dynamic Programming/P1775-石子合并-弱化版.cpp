#include <iostream>
#include <cstring>
using namespace std;

int n;
int dp[305][305];  // 表示每两堆石子合并的力气
int sum[305][305];  // 表示每两堆石子合并的总力气

int main(){
    memset(dp, 0x7f, sizeof dp);

    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%d", &sum[i][i]);
        dp[i][i] = 0;
    }

    // 先合并2堆石子，再合并3堆石子，一直到n堆
    for (int t=2; t<=n; t++){
        // 找到每一堆石子的起始区间
        for (int i=1; i<=n-t+1; i++){
            int j = i + t - 1;
            for (int k=i; k<j; k++){  // 区间的划分：k ∈ [i, j)
                sum[i][j] = sum[i][k] + sum[k+1][j];
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+sum[i][j]);
            }
        }
    }   
    printf("%d\n", dp[1][n]);
    return 0;
}