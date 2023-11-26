#include <iostream>
#include <cstring>
using namespace std;

int n;
int dp1[305][305];  // 表示每两堆石子合并的力气
int dp2[305][305];  // 表示每两堆石子合并的力气
int sum[305][305];  // 表示每两堆石子合并的总力气

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%d", &sum[i][i]);
        sum[n+i][n+i] = sum[i][i];
    }

    // 先合并2堆石子，再合并3堆石子，一直到n堆
    for (int t=2; t<=n; t++){
        // 找到每一堆石子的起始区间
        for (int i=1; i<=2*n-t+1; i++){
            int j = i + t - 1;
            dp1[i][j] = 0x7f7f7f7f;
            for (int k=i; k<j; k++){  // 区间的划分：k ∈ [i, j)
                sum[i][j] = sum[i][k] + sum[k+1][j];
                dp1[i][j] = min(dp1[i][j], dp1[i][k]+dp1[k+1][j]+sum[i][j]);
                dp2[i][j] = max(dp2[i][j], dp2[i][k]+dp2[k+1][j]+sum[i][j]);
            }
        }
    }   

    int ans_min = 0x7f7f7f7f, ans_max = 0;
    for(int i=1; i<=n; i++){
        ans_min = min(ans_min, dp1[i][i+n-1]);
        ans_max = max(ans_max, dp2[i][i+n-1]);
    }
    printf("%d\n%d\n", ans_min, ans_max);
    return 0;
}