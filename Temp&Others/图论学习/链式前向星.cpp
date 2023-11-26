#include <iostream>
using namespace std;

int n, m, ei;
int vertex[20];
int vis[20];

struct node{
    int to;
    int next;
} edges[1000];

void add(int v1, int v2){ 
    ei += 1;
    edges[ei].to = v2;
    edges[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

void dfs(int node){
    // 如何for循环
    cout << node << " ";
    int index = vertex[node];
    while(index){
        int to = edges[index].to;
        if (vis[to] == 0){
            vis[to] = 1;
            dfs(to);
        }
        index = edges[index].next;
    }
}

int main(){
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    dfs(1);
    return 0;
}