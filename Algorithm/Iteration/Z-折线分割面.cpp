#include <iostream>
#include <algorithm>
using namespace std;

int n, dp[10005];

int main(){
    dp[1] = 2;
    dp[2] = 7;
    cin >> n;
    /*
    为了让分割的面最多，让之前的每一条线2*(i-1)都被两条线分割，并且再加上多出来的一个角。
    dp[i] = dp[i-1] + 2*2*(i-1) + 1;
    */
    for (int i=2; i<=n; i++){
        // dp[i] = dp[i-1] + 2*2*(i-1) + 1;
        dp[i] = dp[i-1] + 4*i-4 + 1;  // 化简
    }
    cout << dp[n] << endl;
    return 0;
}