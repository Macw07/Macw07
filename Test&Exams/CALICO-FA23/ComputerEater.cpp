#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n, m, s, t, ei;
int cnt, outDegreeCnt;
int inDegree[1005];
int outDegree[1005];
struct perEdge{
    int to;
    int next;
} edges[1005 * 2];
int vertex[1005];
int vis[1005];
bool flag = true;

void add(int v1, int v2){
    ei += 1;
    edges[ei].to = v2;
    edges[ei].next = vertex[v1];
    vertex[v1] = ei;
    return ;
}

void dfs(int now, int avoid){
    if (flag == 1) return ; 
    if (outDegree[now] == 0){
        flag = 1;
        return ;
    }
    int index = vertex[now];
    while(index){
        int to = edges[index].to;
        if (to != avoid){
            if (!vis[to]){
                vis[to] = 1;
                dfs(to, avoid);
            }
        }
        index = edges[index].next;
    }
    return ;
}

void dfs_check(int now){
    if (outDegree[now] == 0){
        cnt += 1;
        return ;
    }
    int index = vertex[now];
    while(index){
        int to = edges[index].to;
        if (!vis[to]){
            vis[to] = 1;
            dfs_check(to);
        }
        index = edges[index].next;
    }
    return ;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m >> s;
        vector<int> vec;
        memset(inDegree, 0, sizeof inDegree);
        memset(outDegree, 0, sizeof outDegree);
        memset(vertex, 0, sizeof vertex);
        outDegreeCnt = 0;
        ei = 0;
        while(m--){
            int v1, v2;
            cin >> v1 >> v2;
            inDegree[v2] += 1;
            outDegree[v1] += 1;
            add(v1, v2);
        }

        // 暴力拆除每一个点。
        for (int i=1; i<=n; i++){
            if (inDegree[i] == 0) vec.push_back(i);
            if (outDegree[i] == 0) outDegreeCnt++;
        }

        bool impossibleResult = true;
        bool speacialJudge = false;
        for (int i=1; i<=n; i++){
            if (inDegree[i] == 0) continue;
            if (outDegree[i] == 0) continue;

            flag = 0;
            // 尝试从j点开始在不经过i的情况下是否可以到。
            for (int j=0; j<vec.size(); j++){
                memset(vis, 0, sizeof vis);
                dfs_check(vec[j]);
                if (cnt != outDegreeCnt) {
                    speacialJudge = true;
                    break;
                }

                memset(vis, 0, sizeof vis);
                
                cnt = 0;
                dfs(vec[j], i);
                if (flag == 1) break;
            }
            
            if (speacialJudge)  break;
            
            if (flag == 0) {
                cout << i << endl;
                impossibleResult = false;
                break;
            }
        }
        if (impossibleResult) cout << "IMPOSSIBLE" << endl;
        else if (speacialJudge) cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}

/*
4
7 8 1
5 1
7 1
7 2
1 2
1 3
2 4
3 4
3 6
5 4 1
1 3
2 3
3 4
3 5
9 10 1
1 6
2 6
2 3
2 4
8 4
4 3
6 3
3 9
9 5
9 7
6 4 1
1 2
2 3
4 5
5 6
*/