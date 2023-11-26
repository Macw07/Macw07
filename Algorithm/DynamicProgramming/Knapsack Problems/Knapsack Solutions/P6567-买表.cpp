#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, pointer = 1, cnt = 0;
int bills[1000000];
int dp[10000005];
int ans[100005];

int main(){
    scanf("%d %d", &n, &m);
    // 竟然是一道多重背包 + 二进制优化 + 各种优化
    while(n--){
        int k, a;
        scanf("%d %d", &k, &a);
        for (int i=1; i<=a; i++){
            bills[pointer++] = i * k;
            a -= i;
        }
        if (a){
            bills[pointer++] = a * k;
        }
    }
    int wish = 0;
    while(m--){
        scanf("%d", &ans[cnt++]);
        wish = max(wish, ans[cnt-1]);
    }
    dp[0] = 1;
    for (int i=1; i<pointer; i++){
        for (int j=wish; j>=bills[i]; j--){
            dp[j] += dp[j-bills[i]];
        }
    }
    for (int i=0; i<cnt; i++){
        if (dp[ans[i]]){
            printf("Yes\n");
        } else printf("No\n");
    }
    return 0;
}