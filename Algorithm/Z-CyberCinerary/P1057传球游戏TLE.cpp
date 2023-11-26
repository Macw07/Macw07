#include <iostream>
#include <algorithm>
using namespace std;

int peoples, steps;
int cnt = 0;
int dp[35][35];

// crt代表当前的小朋友，steps代表剩下的步数
int dfs(int crt, int steps){
    if (dp[crt][steps]) return dp[crt][steps];
    if (steps == 0){  // 走完了，看看球有没有传到
        if (crt == 1){  // 球传到了小蛮手里
            cnt++;
            return 1;
        }
        return 0;
    }
    // 分两种情况讨论，往左边传，往右边传
    int ans = 0;
    if (crt == peoples) ans += dfs(1, steps-1);
    else ans += dfs(crt+1, steps-1);

    if (crt == 1) ans += dfs(peoples, steps-1);
    else ans += dfs(crt-1, steps-1);

    return ans;
}

int main(){
    cin >> peoples >> steps;
    dfs(1, steps);
    cout << cnt << endl;
    return 0;
}