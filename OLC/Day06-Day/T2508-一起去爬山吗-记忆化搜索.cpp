// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int N = 20;
int n, a[N], car[N], ans = 50, w;
// cnt 当前的已经开的缆车数量  t 当前在去安排第t个人
void dfs(int t, int cnt)
{
    if (cnt >= ans)
        return;
    if (t == n + 1)
    {
        cout << cnt << endl;
        ans = min(ans, cnt);
        return;
    }
    for (int i = 1; i <= cnt; i++)
    {
        if (car[i] + a[t] <= w)
        {
            car[i] += a[t];
            dfs(t + 1, cnt);
            car[i] -= a[t];
        }
    }
    car[cnt + 1] = a[t];
    dfs(t + 1, cnt + 1);
    car[cnt + 1] = 0;
}
int main()
{
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(1, 0);
    cout << ans;
    fclose(stdout);
    fclose(stdin);
    return 0;
}