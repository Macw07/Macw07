#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1000;
int n;
// 递推基
int dp[1000005] = {0, 0, 0, 4, 5};

int main(){
    cin >> n;
    for (int i=3; i<=n; i++){
        dp[i] = dp[i-2]+1;
    }
    cout << dp[n];
    return 0;
}