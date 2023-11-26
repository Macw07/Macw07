#include <iostream>
using namespace std;

// 这道题很恶心，题目没有明确说明。
/*
这道题题目没有说清楚，题目中每一个物品对应的主件编号并不是第p个出现的主件，而是第p个出现的物品。

例如：
2000 5
100 3 0
1000 3 1
400 5 0
300 5 0
1400 2 3

这组数据的 1400 2 3 所对应的主件是 400 4 0（第3个出现的物品），而不是 300 5 0（第3个出现的主件）。
*/

struct node{
    int primePrice, primeValue;
    int attach1Price, attach1Value;
    int attach2Price, attach2Value;
};

node arr[50005];
int dp[50005], chief = 1;
int n, m;

int main(){
    scanf("%d %d", &m, &n);
    for (int i=1; i<=n; i++){
        int v, p, q;
        scanf("%d %d %d", &v, &p, &q);
        if (q == 0){
            arr[i].primePrice = v;
            arr[i].primeValue = v * p;
        } else if (!arr[q].attach1Price){
            arr[q].attach1Price = v;
            arr[q].attach1Value = v * p;
        } else{
            arr[q].attach2Price = v;
            arr[q].attach2Value = v * p;
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=m; j>=0; j--){
            // 只买主件
            if (j >= arr[i].primePrice){
                dp[j] = max(dp[j], dp[j-arr[i].primePrice]+arr[i].primeValue);
            } else continue;
            // 买主件和附件1
            if (j >= arr[i].primePrice + arr[i].attach1Price){
                dp[j] = max(dp[j], dp[j-arr[i].primePrice-arr[i].attach1Price]+arr[i].primeValue+arr[i].attach1Value);
            }
            // 买主件和附件2
            if (j >= arr[i].primePrice + arr[i].attach2Price){
                dp[j] = max(dp[j], dp[j-arr[i].primePrice-arr[i].attach2Price]+arr[i].primeValue+arr[i].attach2Value);
            }
            // 全都买
            if (j >= arr[i].primePrice + arr[i].attach1Price + arr[i].attach2Price){
                dp[j] = max(dp[j], dp[j-arr[i].primePrice-arr[i].attach1Price-arr[i].attach2Price]+arr[i].primeValue+arr[i].attach1Value+arr[i].attach2Value);
            }
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}