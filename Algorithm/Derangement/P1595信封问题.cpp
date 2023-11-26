#include <iostream>
using namespace std;

// 错排 信封问题
long long dp[100005] = {0, 0, 1};

int main(){
    int n;
    cin >> n;
    for (int i=3; i<=n; i++){
        dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
    }
    cout << dp[n] << endl;
    return 0;
}
