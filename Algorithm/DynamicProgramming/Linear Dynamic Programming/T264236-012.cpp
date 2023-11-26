#include <iostream>
using namespace std;

int n;
unsigned long long dp[1000005][5][5];
int mod = 998244353;

/*
dp[n][4][4]就够了，这个状态表示n个格子的时候，第一个格子是0，1，2，最后一个格子是0，1，2的数量
比如dp[2][0][0]：2个格子的时候，第一个格子是0，第二个格子也是0的数量是1种，这时候就和递推一样了，当前的状态是有n-1个格子决定的
*/

int main(){
    cin >> n;
    dp[2][0][0] = 1;
    dp[2][0][1] = 1;
    dp[2][1][0] = 1;
    dp[2][1][1] = 1;
    dp[2][1][2] = 1;
    dp[2][2][1] = 1;
    dp[2][2][2] = 1;
    for (int i=3; i<=n; i++){
        dp[i][0][0] = (dp[i-1][0][0]+dp[i-1][0][1])%mod;
        dp[i][0][1] = (dp[i-1][1][0]+dp[i-1][1][1])%mod;
        dp[i][1][0] = (dp[i-1][1][0]+dp[i-1][1][1])%mod;
        dp[i][1][1] = (dp[i-1][1][0]+dp[i-1][1][1]+dp[i-1][1][2])%mod;
        dp[i][1][2] = (dp[i-1][1][0]+dp[i-1][1][1])%mod;
        dp[i][2][1] = (dp[i-1][1][0]+dp[i-1][1][1])%mod;
        dp[i][2][2] = (dp[i-1][0][0]+dp[i-1][0][1])%mod;
    }
    unsigned long long ans = 0;
    for (int j=0; j<=2; j++){
        for (int k=0; k<=2; k++){
            ans += dp[n][j][k]%mod;
        }
    }
    cout << ans%mod << endl;
    return 0;
}