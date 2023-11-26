#include <iostream>
using namespace std;

unsigned long long dp[5005] = {};

int main(){
    dp[1] = 1, dp[2] = 2;
    int n;
    cin >> n;
    for (int i=3; i<=n; i++){
        dp[i] = dp[i-2] + dp[i-1];
    }
    cout << dp[n];
    return 0;
}