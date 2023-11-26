#include <iostream>
#include <cstring>
using namespace std;

int n;
int dp1[305][305]; 
int dp2[305][305];
int sum[305][305];

int main(){
    memset(dp1, 0x7f, sizeof dp1);

    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%d", &sum[i][i]);
        dp1[i][i] = 0;
    }

    // 先合并2堆石子，再合并3堆石子，一直到n堆
    for (int t=2; t<=n; t++){
        // 找到每一堆石子的起始区间
        for (int i=1; i<=n-t+1; i++){
            int j = i + t - 1;
            for (int k=i; k<j; k++){  // 区间的划分：k ∈ [i, j)
                sum[i][j] = sum[i][k] + sum[k+1][j];
                dp1[i][j] = min(dp1[i][j], dp1[i][k]+dp1[k+1][j]+sum[i][j]);
                dp2[i][j] = max(dp2[i][j], dp2[i][k]+dp2[k+1][j]+sum[i][j]);
            }
        }
    }   
    printf("%d\n%d", dp1[1][n], dp2[1][n]);
    return 0;
}