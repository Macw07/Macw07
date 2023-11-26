// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
const int mod = 998244353;
int a[105][105];
int n, m, t;
int stx, sty, edx, edy;

ll dp[105][105][16];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

ll dfs(int x, int y, int step)
{
    if (step > t)
        return 0;
    if (dp[x][y][step] != -1)
        return dp[x][y][step];
    dp[x][y][step] = 0;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < 1 || tx > n || ty < 1 || ty > m || a[tx][ty] == 1)
            continue;
        dp[x][y][step] = (dp[x][y][step] + dfs(tx, ty, step + 1)) % mod;
    }
    dp[x][y][step] %= mod;
    return dp[x][y][step];
}

int main()
{
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
            a[i][j + 1] = (s[j] == '*' ? 1 : 0);
    }

    cin >> stx >> sty >> edx >> edy;
    memset(dp, -1, sizeof(dp));
    dp[edx][edy][t] = 1;
    dfs(stx, sty, 0);

    cout << dp[stx][sty][0];

    return 0;
}