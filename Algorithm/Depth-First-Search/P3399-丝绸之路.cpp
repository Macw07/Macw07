#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, min_ = 0x7f7f7f7f;
int D[1005], C[1005];
int vis[1005][1005];

void dfs1(int city, int day, int tire){
    if (day > m) return ;
    if (city == n){
        min_ = min(tire, min_);
        return ;
    }
    // 两个选择
    dfs1(city, day+1, tire);
    dfs1(city+1, day+1, tire + C[day+1]*D[city+1]);
    return ;
}

int dfs2(int city, int day){
    if (vis[city][day] != 0x7f7f7f7f) return vis[city][day];

    if (day > m+1) return 0x7f7f7f6f;
    if (city == n) return 0;

    // 两个选择
    int p1 = 0, p2 = 0;
    p1 = dfs2(city, day+1);
    p2 = dfs2(city+1, day+1) + C[day]*D[city+1];
    vis[city][day] = min(p1, p2);
    return vis[city][day];
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) cin >> D[i];
    for (int j=1; j<=m; j++) cin >> C[j];
    memset(vis, 0x7f, sizeof vis);
    cout << dfs2(0, 1) << endl;
    return 0;
}