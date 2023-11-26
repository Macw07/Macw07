#include <iostream>
#include <algorithm>
using namespace std;

int weight[1005], cost[1005], dp[1005];

int main(){
    int n, m;
    cin >> m >> n;
    // 输入数据
    for (int i=1; i<=n; i++){
        cin >> weight[i] >> cost[i];
    }
    // 背包更新
    for (int i=1; i<=n; i++){
        for (int j=m; j>=1; j--){
            for (int k=0; k<=j/weight[i]; k++){
                dp[j] = max(dp[j], dp[j-k*weight[i]]+k*cost[i]);
            }
        }
    }
    // 打印数组
    cout << "max=" << dp[m];
}

/*
10 4
2 1
3 3
4 5 
7 9
*/