#include <iostream>
#include <algorithm>
using namespace std;

int dp[1005] = {};
int weight[1005] = {};
int value[1005] = {};

int main(){
    // 获取数据
    int s, m;
    cin >> s >> m;
    for (int i=1; i<=s; i++){
        cin >> value[i] >> weight[i];
    }
    // 背包解决
    for (int i=1; i<=s; i++){
        for (int j=m; j>=1; j--){  // 从后往前递推
            if (j >= weight[i]){
                dp[j] = max(dp[j], dp[j-weight[i]]+value[i]);
            } 
        }
    }
    cout << dp[m];
    return 0;
}