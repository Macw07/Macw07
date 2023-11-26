#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = 1;
int arr[1005];
int dp[1005];

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
        dp[i] = 1;
    }
    // dp[i]表示的是最多可以投的次数。
    // 从后往前遍历
    
    for (int i=n-1; i>=1; i--){
        for (int j=n; j>i; j--){
            if (arr[j] < arr[i]) dp[i] = max(dp[j]+1, dp[i]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}