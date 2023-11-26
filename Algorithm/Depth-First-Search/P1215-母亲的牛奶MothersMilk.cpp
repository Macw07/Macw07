#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int a, b, c;
set<int> s;
int vis[25][25][25];

struct node{
    int a, b;
};

// 将a倒入b中，a和b中剩余的水。
node pour(int v1, int v2, int capacity){
    if (v1 + v2 > capacity){
        v1 = v1 - (capacity - v2);
        v2 = capacity;
    } else{
        v2 = v1 + v2;
        v1 = 0;
    }
    return (node){v1, v2};
}

void dfs(int v1, int v2, int v3){
    if (v1 == 0) s.insert(v3);

    node t = pour(v1, v2, b);
    if (!vis[t.a][t.b][v3]){
        vis[t.a][t.b][v3] = 1;
        dfs(t.a, t.b, v3);
    }

    t = pour(v2, v1, a);
    if (!vis[t.b][t.a][v3]){
        vis[t.b][t.a][v3] = 1;
        dfs(t.b, t.a, v3);
    }

    t = pour(v1, v3, c);
    if (!vis[t.a][v2][t.b]){
        vis[t.a][v2][t.b] = 1;
        dfs(t.a, v2, t.b);
    }

    t = pour(v3, v1, a);
    if (!vis[t.b][v2][t.a]){
        vis[t.b][v2][t.a] = 1;
        dfs(t.b, v2, t.a);
    }

    t = pour(v2, v3, c);
    if (!vis[v1][t.a][t.b]){
        vis[v1][t.a][t.b] = 1;
        dfs(v1, t.a, t.b);
    }

    t = pour(v3, v2, b);
    if (!vis[v1][t.b][t.a]){
        vis[v1][t.b][t.a] = 1;
        dfs(v1, t.b, t.a);
    }

    return ;
}

int main(){
    cin >> a >> b >> c;
    vis[0][0][c] = 1;
    dfs(0, 0, c);
    for (set<int>::iterator it=s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    return 0;
}