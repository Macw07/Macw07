#include <iostream>
using namespace std;

int n;
long long dp[55] = {0, 0, 1};

int main(){
    cin >> n;
    for (int i=3; i<=n; i++){
        dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
    }
    cout << dp[n] << endl;
    return 0;
}