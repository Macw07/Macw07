#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// 第一次，绿题一次提交就过了。

int n, p;
int uf[105], ei;
int weight[105];
int vertex[105];
int inDegree[105], outDegree[105];
queue<int> zeroOut;
queue<int> que;

struct perEdge{
    int to;
    int next;
    int weight;
} edge[10005];

void add(int v1, int v2, int weight){
    ei += 1;
    edge[ei].to = v2;
    edge[ei].next = vertex[v1];
    edge[ei].weight = weight;
    vertex[v1] = ei;
    return ;
}

void topological_sort(){
    for (int i=1; i<=n; i++){
        if (inDegree[i] == 0){
            que.push(i);
        } 
        if (outDegree[i] == 0){
            zeroOut.push(i);
        }
    }
    while(!que.empty()){
        int t = que.front();
        que.pop();
        int index = vertex[t];
        while(index != 0){
            int u = edge[index].to;
            int w = edge[index].weight;
            inDegree[u] -= 1;
            weight[u] += w * weight[t];
            if (inDegree[u] == 0){
                weight[u] -= uf[u];
                if (weight[u] > 0){
                    que.push(u);
                }
            }
            index = edge[index].next;
        }
    }
    return ;
}

int main(){
    cin >> n >> p;
    for (int i=1; i<=n; i++) cin >> weight[i] >> uf[i];
    for (int i=1; i<=p; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >>w;
        add(v1, v2, w);
        inDegree[v2] += 1;
        outDegree[v1] += 1;
    }
    topological_sort();
    bool flag = true;
    while(!zeroOut.empty()){
        int t = zeroOut.front();
        zeroOut.pop();
        if (weight[t] > 0){
            cout << t << ' ' << weight[t] <<endl;
            flag = false;
        }
    }
    if (flag == true) cout << "NULL" << endl;
    return 0;
}