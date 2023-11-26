#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[205];

int main(){
    cin >> n;
    dp[1] = 2;
    dp[2] = 4;
    dp[3] = 7;
    for (int i=4; i<=n; i++){
        // dp[i] = (i-1) + dp[i-1] + 1;
        dp[i] = i + dp[i-1];
    }
    cout << dp[n] << endl;
    return 0;
}