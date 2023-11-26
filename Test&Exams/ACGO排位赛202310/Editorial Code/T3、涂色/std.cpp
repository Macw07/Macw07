#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

struct node
{
    int l, r;
    int id;
};

struct point
{
    int r, id;
    friend bool operator<(point x, point y) // 堆要反着重载
    {
        return x.id < y.id; // 后涂色的排在前面
    }
};

int color[200005];

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    vector<node> op;
    for (int i = 1; i <= m; i++)
    {
        int l, r, c;
        cin >> l >> r >> c;
        op.push_back({l, r, i});
        color[i] = c;
    }
    sort(op.begin(), op.end(), [&](node &x, node &y)
         { return x.l < y.l; });
    priority_queue<point> q;

    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j < op.size() && op[j].l == i)
            q.push({op[j].r, op[j].id}), j++;
        while (!q.empty() && q.top().r < i)
            q.pop();
        if (!q.empty())
            cout << color[q.top().id];
        else
            cout << 0;
        cout << (i == n ? "" : " ");
    }
    return 0;
}