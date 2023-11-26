#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int m;
int nums[25];
int dp[100005];

int main(){
    cin >> m;
    for (int i=1; i<=20; i++){
        nums[i] = pow(i, 4);
    }
    memset(dp, 0x7f, sizeof dp);
    dp[0] = 0;
    for (int i=20; i>=1; i--){
        for (int j=0; j<=m; j++){
            if (j >= nums[i]){
                dp[j] = min(dp[j], dp[j-nums[i]]+1);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}