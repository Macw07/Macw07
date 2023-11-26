// #include <iostream>
// #include <algorithm>
// using namespace std;

// int peoples, steps;
// int cnt = 0;
// int dp[35][35];

// // crt代表当前的小朋友，steps代表剩下的步数
// int dfs(int crt, int steps){
//     if (dp[crt][steps]) return dp[crt][steps];
//     if (steps == 0){  // 走完了，看看球有没有传到
//         if (crt == 1){  // 球传到了小蛮手里
//             cnt++;
//             return 1;
//         }
//         return 0;
//     }
//     // 分两种情况讨论，往左边传，往右边传
//     int ans = 0;
//     if (crt == peoples) ans += dfs(1, steps-1);
//     else ans += dfs(crt+1, steps-1);

//     if (crt == 1) ans += dfs(peoples, steps-1);
//     else ans += dfs(crt-1, steps-1);

//     return ans;
// }

// int main(){
//     cin >> peoples >> steps;
//     dfs(1, steps);
//     cout << cnt << endl;
//     return 0;
// }

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int dp[35][35];

// ? SO, SAD. 暴力递归竟然过不去，那只能认真写dp数组了 -_-||

int main(){
    cin >> n >> m;
    dp[0][1] = 1;  // 刚开始，球是在小蛮手中的
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            if (j == 1) dp[i][j] = dp[i-1][n]+dp[i-1][j+1];
            else if (j == n) dp[i][j] = dp[i-1][1]+dp[i-1][n-1];
            else dp[i][j] = dp[i-1][j-1]+dp[i-1][j+1];

        }
    }
    cout << dp[m][1];
    return 0; 
}