#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// 没理解为什么一直都是66分，然后重新判断一下就可以了。

const int MAXV = 1e6+5;

int v, e, inDegree[MAXV];
vector<int> G[MAXV];
queue<int> que, ans;

int topologicalSort(){
    int num = 1;  // 记录顶点数量 - 判断是否有环
    for (int i=1; i<=v; i++){
        if (inDegree[i] == 0){
            que.push(i);
        }
    }
    while(!que.empty()){
        int u = que.front();
        ans.push(u);
        que.pop();
        for (int i=0; i<G[u].size(); i++){
            int vertex = G[u][i];
            inDegree[vertex] -= 1;
            if (inDegree[vertex] == 0) que.push(vertex);
        }
        G[u].clear();
        num += 1;
    }
    return num == v;
}

int main(){
    cin >> v >> e;
    for (int i=1; i<=e; i++){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        inDegree[y] += 1;
    }

    topologicalSort();

    if (ans.size() >= v){
        while(ans.size()){
            cout << ans.front() << ' ';
            ans.pop();
        }
    } 
    else cout << "has circle" << endl;
    return 0;
}