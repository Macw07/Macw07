#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

/*
floyed算法
floyed不仅能求任意两点的最短路，还能求一个点能否到另一个点。
f[i][j]=f[i][j]|(f[i][k]&f[k][j])表示i能否走到j，即要么一开始i能到j,要么i能到k，k再能到j。
那么这里表示的是i能否赢j。用floyed求出每个点与个点的关系，只要这个点和其他
n-1个点的关系都确定了，就能确定他的排名。
*/

int n, m, total;
long long dp[105][105];

int main(){
    cin >> n >> m;

    for (int i=1; i<=m; i++){
        int t1, t2;
        cin >> t1 >> t2;
        dp[t1][t2] = 1;
    }

    // 判断图是否联通
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                dp[i][j] = dp[i][j] || dp[i][k] && dp[k][j];
            }
        }
    }

    for (int i=1; i<=n; i++){
        int t = 1;
        for (int j=1; j<=n; j++){
            if (i == j) continue;
            t = t && (dp[i][j] || dp[j][i]);
        } 
        total += t;  
    }
    cout << total << endl;
    return 0;
}