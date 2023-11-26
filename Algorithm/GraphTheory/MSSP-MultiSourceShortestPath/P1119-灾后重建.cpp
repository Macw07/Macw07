#include <iostream>
#include <algorithm>
using namespace std;

/*
这个算法的主要思路，就是通过其他的点进行中转来求的两点之间的最短路。
因为我们知道，两点之间有多条路，如果换一条路可以缩短距离的话，就更新最短距离。
而它最本质的思想，就是用其他的点进行中转，从而达到求出最短路的目的。
*/

int n, m, q;
int ti[205];
long long dp[205][205];

void floyd(int k){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            dp[i][j] = dp[j][i] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
    }
    return ;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> ti[i];

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            dp[i][j] = 0x7f7f7f7f;
        }
        dp[i][i] = 0;
    }

    for (int i=1; i<=m; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        v1 += 1, v2 += 1;
        dp[v1][v2] = dp[v2][v1] = w;
    }

    cin >> q;
    int now = 1;  // 第几个节点被更新了
    for (int i=1; i<=q; i++){
        int v1, v2, t;
        cin >> v1 >> v2 >> t;
        v1 += 1, v2 += 1;
        while (ti[now] <= t && now <= n){
            floyd(now);
            now += 1;
        }
        
        if (ti[v1] > t || ti[v2] > t) {
            cout << -1 << endl;
            continue;
        }
        if (dp[v1][v2] == 0x7f7f7f7f) cout << -1 << endl;
        else cout << dp[v1][v2] << endl;
    }
    return 0;
}