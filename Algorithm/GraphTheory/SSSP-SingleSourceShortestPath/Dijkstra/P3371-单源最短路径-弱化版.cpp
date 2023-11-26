#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
const int MAXN = 1e4+5;

int n, m, s;
int arr[MAXN];
int vis[MAXN];
struct node{int v; int w;};
vector<node> G[MAXN];

void dijkstra(){
    int current = s;
    while(vis[current] == 0){
        vis[current] = 1;
        int len = G[current].size();
        for (int i=0; i<len; i++){
            int next = G[current][i].v;
            arr[next] = min(arr[next], arr[current] + G[current][i].w);
        }
        // 枚举剩下的所有的点
        int minn = 2147483647;
        for (int i=1; i<=n; i++){
            if (vis[i] == 0 && arr[i] < minn){
                minn = arr[i];
                current = i;
            }
        }
    }
    return ;
}

int main(){
    scanf("%d %d %d", &n, &m, &s);
    for (int i=1; i<=m; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[u].push_back((node){v, w});
    }
    for (int i=1; i<=n; i++) arr[i] = 2147483647;
    arr[s] = 0;
    dijkstra();
    for (int i=1; i<=n; i++) cout << arr[i] << " ";
    return 0;
}