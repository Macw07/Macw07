#include <iostream>
#include <algorithm>
using namespace std;

int dp[10005], w[1005], v[1005], s[1005];

int main(){
    int n, m;
    cin >> n >> m; 
    // 读入数据
    for (int i=1; i<=n; i++){
        cin >> v[i] >> w[i] >> s[i];
    }
    // 动态规划部分
    for (int i=1; i<=n; i++){
        for (int j=m; j>=1; j--){
            for (int k=0; k<=s[i]&&j>=k*v[i]; k++){
                dp[j] = max(dp[j], dp[j-k*v[i]]+k*w[i]);
            }
        }
    }
    cout << dp[m];
    return 0;
}

/*
5 1000
80 20 4
40 50 9
30 50 7
40 30 6
20 20 1
*/