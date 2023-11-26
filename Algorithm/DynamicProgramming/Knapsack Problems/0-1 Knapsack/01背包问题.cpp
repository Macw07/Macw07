#include <iostream>
#include <algorithm>
using namespace std;

int dp[1005][1005] = {};
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
        for (int j=1; j<=m; j++){
            if (j < weight[i]){
                dp[i][j] = dp[i-1][j];
            } else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i]);
            }
        }
    }
    for (int i=0; i<=s; i++){
        for (int j=0; j<=m; j++){
            cout << dp[i][j] << "  ";
        }
        cout << endl;
    }
    cout << dp[s][m];
    return 0;
}