#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 3e5+5;
int n, m, ei;
bool flag = true;
struct route{
    int to;
    int due;
    int arrive;
};
int c, r, d, s;
int vis[MAXN], a[MAXN];
int ans[MAXN], ind[MAXN];
vector<route> map[MAXN];

bool cmp(route a, route b){
    return a.due <= b.due;
}

void dfs(int u, int t){
    for (int i=ind[u]; i>=0; i--){
        route next = map[u][i];
        if (next.due < t) break;
        ans[next.to] = min(ans[next.to], next.arrive);
        ind[u] = i - 1;
        dfs(next.to, next.arrive + a[next.to]);
    }
    return ;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=m; i++){
        scanf("%d %d %d %d", &c, &r, &d, &s);
        map[c].push_back((route){d, r, s});
    }
    
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        ind[i] = map[i].size()-1;
        ans[i] = 0x7f7f7f7f;    
        sort(map[i].begin(), map[i].end(), cmp);
    }

    ans[1] = 0;
    dfs(1, 0);

    for (int i=1; i<=n; i++) {
        if (ans[i] == 0x7f7f7f7f) printf("-1\n");
        else printf("%d\n", ans[i]);
    }
    return 0;
}