#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int p;
struct node{
    char to;
    int next;
    int w;
} edge[20005];
int vertex[205], ei;
int ans[205], vis[205];

struct inque{
    // anstance 表示到这个点的距离。
    // position 表示这个点的编号。
    int anstance, position;
    bool friend operator < (inque a, inque b){
        // 运算符重载
        return a.anstance > b.anstance;
    };
};

void dijkstra(int origin){
    memset(ans, 0x7f, sizeof ans);
    ans[origin] = 0;
    priority_queue<inque> que;
    que.push((inque){0, origin});
    while(!que.empty()){
        inque t = que.top();
        que.pop();
        if (vis[t.position]) continue;
        vis[t.position] = 1;
        int index = vertex[t.position];
        while(index != -1){  
            int u = edge[index].to;
            int w = edge[index].w;
            if (w + ans[t.position] < ans[u]){
                ans[u] = w + ans[t.position];
                que.push((inque){ans[u], u});
            }
            index = edge[index].next;
        }   
    }
    return ;
}

void add(int v1, int v2, int w){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].w = w;
    edge[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

int main(){
    memset(vertex, -1, sizeof vertex);
    cin >> p;
    for (int i=1; i<=p; i++){
        char v1, v2;
        int w;
        cin >> v1 >> v2 >> w;
        add(v1, v2, w);
        add(v2, v1, w);
    }
    dijkstra((int)'Z');
    int ansN, ansD = 0x7f7f7f7f;
    for (int i='A'; i<='Z'; i++){
        if (ans[i] != 0 && ans[i] < ansD){
            ansD = ans[i];
            ansN = i;
        }
    }
    cout << char(ansN) << " " << ansD << endl;
    return 0;
}