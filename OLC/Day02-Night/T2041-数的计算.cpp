#include <iostream>
using namespace std;

int n;
long long dp[1005] = {0, 1, 2, 2};

int main(){
    cin >> n;
    for (int i=3; i<=n; i++){
        if (i % 2) dp[i] = dp[i-1];
        else dp[i] = dp[i-1] + dp[i/2];
    }   
    cout << dp[n] << endl;
    return 0;
}