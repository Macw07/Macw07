#include <iostream>
#include <algorithm>
using namespace std;

// 一开始打算用Dijkstra，看了题解以后才知道用动态规划。

int n, m, t;
long long dp[305][305];

void init(){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            dp[i][j] = 0x7f7f7f7f;
        }
        dp[i][i] = 0;
    }
    return ;
}

void floyd(){
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                dp[i][j] = min(max(dp[i][k], dp[k][j]), dp[i][j]);
            }
        }
    }
    return ;
}

int main(){
    scanf("%d %d %d", &n, &m, &t);
    init();
    for (int i=1; i<=m; i++){
        int v1, v2, w;
        scanf("%d %d %d", &v1, &v2, &w);
        dp[v1][v2] = w;
    }
    floyd();
    for (int i=1; i<=t; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        if (dp[v1][v2] != 0x7f7f7f7f) printf("%lld\n", dp[v1][v2]);
        else printf("-1\n");
    }
    return 0;
}