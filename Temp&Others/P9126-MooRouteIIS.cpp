#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 2e5+5;
int n, m, ei;
bool flag = true;
struct route{
    int to;
    int next;
    int due;
    int arrive;
} routes[MAXN];
int c, r, d, s;
int vis[MAXN], a[MAXN];
int vertex[MAXN], ans[MAXN];


void add(int v1, int v2, int due, int arrive){
    ei += 1;
    routes[ei].to = v2;
    routes[ei].next = vertex[v1];
    routes[ei].due = due;
    routes[ei].arrive = arrive;
    vertex[v1] = ei;
    return ;
}

void dfs(int now, int time){
    if (ans[now] != 0x7f7f7f7f && ans[now] > time) return ;
    ans[now] = time;
    time += a[now];
    if (flag) {
        time -= a[now];
        flag = false;
    }
    int index = vertex[now];
    while(index){
        int to = routes[index].to;
        if (!vis[to]){
            if (time <= routes[index].due){
                vis[to] = 1;
                dfs(to, routes[index].arrive);
                vis[to] = 0;
            }
        }
        index = routes[index].next;
    }

    return ;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=m; i++){
        scanf("%d %d %d %d", &c, &r, &d, &s);
        add(c, d, r, s);
    }
    for (int i=1; i<=n; i++) scanf("%d", &a[i]);
    memset(ans, 0x7f, sizeof ans);
    dfs(1, 0);
    for (int i=1; i<=n; i++) {
        if (ans[i] == 0x7f7f7f7f) printf("-1\n");
        else printf("%d\n", ans[i]);
    }
    return 0;
}