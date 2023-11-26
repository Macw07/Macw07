#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, ans;
int dp[10005];
int times[10005];
int inDegree[10005];

vector<int> G[10005];

void topological_sort(){
    queue<int> que;
    for (int i=1; i<=n; i++){
        if (inDegree[i] == 0){
            que.push(i);
            dp[i] = times[i];
        }
    }
    while(!que.empty()){
        int t = que.front();
        int len = G[t].size();
        que.pop();
        for (int i=0; i<len; i++){
            int next = G[t][i];
            dp[next] = max(dp[next], dp[t] + times[next]);
            inDegree[next] -= 1;
            if (inDegree[next] == 0) que.push(next);
        }
    }
    return ;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int id, time, k;
        cin >> id >> time;
        times[id] = time; 
        while(cin >> k && k != 0){
            inDegree[i] += 1;
            G[k].push_back(id);
        }
    }
    topological_sort();
    for (int i=1; i<=n; i++) ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}