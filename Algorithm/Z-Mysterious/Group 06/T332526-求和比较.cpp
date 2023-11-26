#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int dp[35];

// 1+2+3+4+5 = 15
// 15 - 1 = 14
// 14 / 2 = 7, 7+1 = 8

int main(){
    cin >> n >> m;
    int sum = (1+n)*n / 2;
    int target = (sum-m)/2;
    // 求有多少种方法可以凑出 target
    dp[0] = 1;
    for (int i=1; i<=n; i++){
        for (int j=target; j>=0; j--){
            if (j - i >= 0) dp[j] += dp[j-i];
        }
    }
    cout << dp[target] << endl;
    return 0;
}