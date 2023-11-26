#include <iostream>
#include <cstring>
using namespace std;

/*  dp[i][j][k]
    走到dp[i][j]正好走[k]步的距离。*/
// dp[i][j] = dp[i-1][j][k-1] + dp[i+1][j][[k-1] + dp[i][j-1][k-1] + dp[i][j+1][k-1]

const int MOD = 998244353;
int n, m, t;
char map[105][105];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int r1, c1, r2, c2;
int dp[105][105][205];

int main(){
    scanf("%d %d %d", &n, &m, &t);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> map[i][j];
        }
    }
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

    dp[r1][c1][0] = 1;

    for (int k=1; k<=t; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                for (int l=0; l<4; l++){
                    int cx = dx[l] + i;
                    int cy = dy[l] + j;
                    if (cx < 1 || cy < 1 || cx > n || cy > m) continue;
                    if (map[cx][cy] == '*') continue;
                    dp[i][j][k] = (dp[i][j][k] + dp[cx][cy][k-1]) % MOD;
                }
            }
        }
    }

    printf("%d\n", dp[r2][c2][t] % MOD);
    return 0;
}