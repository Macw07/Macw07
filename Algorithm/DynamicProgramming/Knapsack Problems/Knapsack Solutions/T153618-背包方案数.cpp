#include <iostream>
using namespace std;

int dp[505], arr[1005];
int n, sum;

int main(){
    cin >> n >> sum;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
    dp[0] = 1;
    // 01背包的背包方案数写法
    for (int i=1; i<=n; i++){
        for (int j=sum; j>=0; j--){
            if (j >= arr[i]){
                dp[j] += dp[j-arr[i]];
            }
        }
    }
    cout << dp[sum] << endl;
    return 0;
}