#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 100005;

int n, m;
int vis1[MAXN], vis2[MAXN];
queue<int> que;
vector<int> G[MAXN];

// 服了，dfs忘记标记起点了，导致遍历出问题了。
void dfs(int node, int current){
    vis1[node] = 1;
    cout << node << ' ';
    if (current == n) return ;
    for (int i=0; i<G[node].size(); i++){
        if (vis1[G[node][i]]) continue;
        dfs(G[node][i], current+1);
    }
    return ;
}

void dfs(int node){
    vis2[node] = 1;
    que.push(node);
    while(que.size()){
        int t = que.front();
        cout << t << " ";
        for (int i=0; i<G[t].size(); i++){
            if (vis2[G[t][i]]) continue;
            vis2[G[t][i]] = 1;
            que.push(G[t][i]);
        }
        que.pop();
    }
    return ;
}

int main(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        int t1, t2;
        cin >> t1 >> t2;
        G[t1].push_back(t2);
    }
    for (int i=1; i<=n; i++) sort(G[i].begin(), G[i].end());
    dfs(1, 0), cout << endl, dfs(1);
    return 0;
}