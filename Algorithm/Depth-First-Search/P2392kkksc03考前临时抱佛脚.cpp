#include <iostream>
#include <algorithm>
using namespace std;

// 不论发生什么情况，先递归暴力解决 :)  FAIL

int ans = 0;
int s[5], hwk[100], dp[10000];

int main(){
    for (int i = 0; i < 4; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < 4; i++) {
        int sum = 0;
        for (int j = 0; j < s[i]; j++){
            cin >> hwk[j];
            sum += hwk[j];
        }
        for (int j = 0; j < s[i]; j++){
            for (int k = sum/2; k >= hwk[j]; k--){
                dp[k] = max(dp[k], dp[k-hwk[j]]+hwk[j]);  // 01背包
            }
        }
        ans += sum-dp[sum/2];
        for (int j=0; j<=sum/2; j++) dp[j] = 0;
    }
    cout << ans << endl;
    return 0;
}
