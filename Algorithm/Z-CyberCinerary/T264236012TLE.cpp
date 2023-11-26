#include <iostream>
#include <cmath>
using namespace std;

int n;
int dp[100005];
int cnt = 0;
int mod = 998244353;

// 果然，DfS是万能的，但又不是那么的万能 -_-||

void dfs(int crt){
    if (crt > n){  // 说明已经尝试好了，进行判断即可
        if (abs(dp[1] - dp[n]) > 1) return;
        cnt++;
        return;
    }   
    // 依次尝试设置
    for (int i=0; i<=2; i++){
        if (crt > 1 && abs(i-dp[crt-1]) > 1) continue;
        dp[crt] = i;
        dfs(crt+1);
    }
    return;
}

int main(){
    cin >> n;
    dfs(1);
    cout << cnt << " ";
    return 0;
}