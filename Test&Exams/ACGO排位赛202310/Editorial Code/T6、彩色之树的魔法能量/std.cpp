#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const int maxn = 1e5 + 5;
int color[maxn];

vector<int> G[maxn];

ll cnt[maxn][105];
ll sum[maxn][105];
ll ans = 0;

void dfs(int from, int fa)
{
    cnt[from][color[from]] = 1;
    sum[from][color[from]] = 1;
    for (auto &to : G[from])
    {
        if (to == fa)
            continue;
        dfs(to, from);
        for (int j = 1; j <= 100; j++)
            ans += sum[from][j] * cnt[to][j] + sum[to][j] * cnt[from][j];
        sum[from][color[from]] += cnt[to][color[from]];
        for (int j = 1; j <= 100; j++)
        {
            cnt[from][j] += cnt[to][j];
            sum[from][j] += sum[to][j];
        }
    }
}

int main()
{
    fastio;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> color[i];
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}