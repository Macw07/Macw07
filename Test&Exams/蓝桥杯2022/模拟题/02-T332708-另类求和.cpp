#include <iostream>
#include <algorithm>
using namespace std;

int n;  // 砖块的总层数
int dp[1005];  // 答案存放，dp[i] 表示的i每一层所需要的砖块数量
int sum;  // 用于记录总数

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        // f(n) = f(n-1) + n
        dp[i] = dp[i-1] + i;
        sum += dp[i];
    }
    cout << sum << endl;
    return 0;
}