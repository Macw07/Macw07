#include <iostream>
using namespace std;

int n;
long long dp[55] = {0, 1, 6, 6};

int main(){
    cin >> n;
    for (int i=4; i<=n; i++){
        dp[i] = dp[i-1] + 2*dp[i-2];
    }
    cout << dp[n] << endl;
    return 0;
}