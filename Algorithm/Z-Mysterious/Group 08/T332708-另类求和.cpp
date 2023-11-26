#include <iostream>
#include <algorithm>
using namespace std;

int n, total;
int dp[1005] = {0, 1, 3};

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) dp[i] = dp[i-1] + i, total += dp[i];
    cout << total << endl;
    return 0;
}