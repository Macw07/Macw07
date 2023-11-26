#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, cost = 0x7f7f7f7f;
int arr[15];
// dp[i][j]表示前i个砖块在满足总和为j时至少所需要的费用。
int dp[15][10005]; 

bool cmp(int a, int b) {return a > b;}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++) scanf("%d", &arr[i]);
    // 这题不能用递归做，用递归做会超时，因此得使用动态规划的背包方案数解决本题。
    memset(dp, 0x7f, sizeof dp);
    dp[0][0] = 0;
    for (int i=1; i<=n; i++){  // 枚举每一个物品。
        for (int j=0; j<=m; j++){  // 枚举每一个“容量”，即所有砖块的总和。
            if (dp[i-1][j] != 0x7f7f7f7f){  // 如果前i个物品总和正好为m。
                for (int k=1; k*k+j<=m; k++){  // 枚举所有可以兑换的砖块大小。
                    int x = arr[i] - k;
                    dp[i][j+k*k] = min(dp[i][j+k*k], dp[i-1][j] + x*x);  // 更新答案。
                }
            }   
        }
    }
    if (dp[n][m] == 0x7f7f7f7f) cout << -1 << endl;
    else cout << dp[n][m] << endl;
    return 0;
}