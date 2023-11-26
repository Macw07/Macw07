#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int t, timee;
int n, m, k;

struct passenger{
    int begin;
    int end;
} passengers[100005];
int vis[100005];

int main(){
    cin >> t;
    while(t--){
        timee = 0;
        cin >> n >> m >> k;
        for (int i=1; i<=n; i++) cin >> passengers[i].begin;
        for (int i=1; i<=n; i++) cin >> passengers[i].end;
        queue<passenger> que;
        int cnt = 0, round = 0;
        memset(vis, 0, sizeof vis);
        while(1){
            round += 1;
            for (int i=1; i<=m; i++){
                if (round != 1 && i == 1) timee++;
                if (i >= 2) timee += 1;
                // 站点i。
                int range = que.size();
                for (int j=1; j<=range; j++){
                    passenger tmp = que.front();
                    que.pop();
                    if (tmp.end == i) continue;
                    que.push(tmp);
                }

                for (int j=1; j<=n; j++){
                    if (que.size() == k) break;
                    // 能上车就上车。
                    if (vis[j]) continue;
                    if (passengers[j].begin == i){
                        vis[j] = 1;
                        que.push(passengers[j]);
                        cnt += 1;
                    }
                }
                // cout << i << " " << que.size() << " " << cnt << endl;
                if (que.size() == 0 && cnt == n) break;
            }
            if (que.size() == 0 && cnt == n) break;
        }
        cout << timee << endl;
    }
    return 0;
}

/*
6
1 6 1
3
5
2 6 2
1 4
5 6
2 6 1
1 4
5 6
2 8 2
2 3
6 5
4 5 2
1 3 3 5
4 5 1 2
7 7 1
1 1 1 1 1 1 1
7 7 7 7 7 7 7
*/