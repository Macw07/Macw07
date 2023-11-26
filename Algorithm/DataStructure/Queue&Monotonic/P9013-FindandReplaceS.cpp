#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
using namespace std;

const int N = 300;
string s, t;
int inDegree[N];
int T, len, to[N], vis[N];

void topologicalSort(){
    queue<int> que;
    for (int i='A'; i<='Z'; i++){
        if (inDegree[i] == 0){
            que.push(i);
        }
    }
    for (int i='a'; i<='z'; i++){
        if (inDegree[i] == 0){
            que.push(i);
        }
    }
    while(!que.empty()){
        int k = que.front();
        que.pop();
        vis[k] = 1;
        int v = to[k];
        if (vis[v] == 0){
            inDegree[v] = 0;
            que.push(v);
        }
    }
    return ;
}

void dfs(int node){
    vis[node] = 1;
    int k = to[node];
    if (vis[k] == 0) dfs(k);
    return ;
}

int main(){
    cin >> T;
    
    while(T--){
        memset(inDegree, 0, sizeof inDegree);
        memset(to, 0, sizeof to);
        memset(vis, 0, sizeof vis);
        set<char> b;
        cin >> s >> t;
        len = s.size();

        bool flag = 1;
        for (int i=0; i<len; i++){
            if (to[s[i]] == 0 || to[s[i]] == t[i]){
                to[s[i]] = t[i];
            } else {
                flag = 0;
            }
            b.insert(t[i]);
        }
        if (!flag){
            cout << -1 << endl;
            continue;
        }
        if (b.size() == 52){
            if (s == t) cout << 0 << endl;
            else cout << -1 << endl;
            continue;
        }

        memset(to, 0, sizeof to);
        int ans = 0;
        for (int i=0; i<len; i++){
            if (to[s[i]] == 0 && s[i] != t[i]){
                to[s[i]] = t[i];
                inDegree[t[i]] += 1;
                ans += 1;
            }
        }
        topologicalSort();

        for (int i='A'; i<='Z'; i++){
            if (vis[i] == 0){
                ans += 1;
                dfs(i);
            }
        }

        for (int i='a'; i<='z'; i++){
            if (vis[i] == 0){
                ans += 1;
                dfs(i);
            }
        }

        cout << ans << endl;
    }

    return 0;
}