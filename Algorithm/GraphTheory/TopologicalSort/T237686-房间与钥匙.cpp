#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

queue<int> que;
int n, m, ans = 1;
int ei = 0, vertex[1005];
int vis[1005];

struct node{
    int to;
    int next;
    int weight;  // weight 代表了这里是否有钥匙，如果有则为1，否则为0；
} edge[10005];

// 链式前向星
void add(int v1, int v2, int weight){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].next = vertex[v1];
    edge[ei].weight = weight;
    vertex[v1] = ei;
    return ;
}

void check(){
    que.push(1);
    while(!que.empty()){
        int t = que.front();
        que.pop();
        int index = vertex[t];
        while(index != -1){
            int u = edge[index].to;
            if (!vis[u]){
                vis[u] = 1;  // 如果可以走通，就将标记设定为1
                ans += 1;
            }
            if (edge[index].weight) que.push(u);
            index = edge[index].next;
            if (ans == n){  // 当所有的房间都被走通了以后，就可以直接输出答案了
                cout << "true" << endl;
                return ;
            }
        }
    }
    cout << "false" << endl;
    return ;
}

int main(){
    memset(vertex, -1, sizeof vertex);
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int v1, v2, k;
        cin >> v1 >> v2 >> k;
        add(v1, v2, k);
    }
    check();
    return 0;
}