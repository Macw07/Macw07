#include <iostream>
#include <algorithm>
using namespace std;

// wsq很伤心，以为自己01背包学的很好，但其实遇到真的题目还是会WA
int n, m;
int dp[20005];
int value[20005];

int main(){
    cin >> m >> n;
    for (int i=1; i<=n; i++){
        cin >> value[i];
    }
    // 动态规划 - 01背包问题
    for (int i=1; i<=n; i++){  // 遍历每一个物品
        for (int j=m; j>=value[i]; j--){  // 遍历每一个空间
            dp[j] = max(dp[j], dp[j-value[i]]+value[i]);
        }
    }
    cout << m-dp[m] << endl;
    return 0;
}