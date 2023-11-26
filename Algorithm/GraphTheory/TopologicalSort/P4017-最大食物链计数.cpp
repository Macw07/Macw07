#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
const ll mod = 80112002;

ll n, m, total;
vector<ll> G[500005];
ll inDegree[500005], outDegree[500005];
ll ans[500005];

void topological_sort(){
    queue<ll> que;
    for (int i=1; i<=n; i++){
        if (inDegree[i] == 0){
            ans[i] = 1;
            que.push(i);
        }
    }
    while(que.size()){
        int t = que.front();
        int len = G[t].size();
        que.pop();
        for (int i=0; i<len; i++){
            int next = G[t][i];
            inDegree[next] -= 1;
            ans[next] = (ans[next] + ans[t]) % mod;
            if (inDegree[next] == 0) que.push(next);
        }
    }
    return ;
}

int main(){
    scanf("%lld %lld", &n, &m);
    for (int i=1; i<=m; i++){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        inDegree[v2] += 1;
        outDegree[v1] += 1;
        G[v1].push_back(v2);
    }
    topological_sort();
    for (int i=1; i<=n; i++){
        if (outDegree[i] == 0){
            total = (total + ans[i]) % mod;
        }
    }
    cout << total << endl;
    return 0;
}