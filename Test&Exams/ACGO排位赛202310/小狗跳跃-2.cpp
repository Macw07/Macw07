#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
struct node{
    int position;
    int steps;
    bool friend operator < (node a, node b){
        return a.steps > b.steps;
    }
};
priority_queue<node> que;
int vis[200005];

void bfs(int origin){
    vis[origin] = 1;
    que.push((node){1, 0});

    while (!que.empty()){
        node t = que.top();
        que.pop();
        if (t.position == n){
            cout << t.steps << endl;
            return ;
        }
        
    
        if (vis[t.position + 1] == 0){
            vis[t.position + 1] = 1;
            que.push((node){t.position+1, t.steps+1});
        }
        
        for (int i=1; i<=448; i++){
            int k = t.position + i * i;
            if (k > n) break;
            if (vis[k]) continue;
            vis[k] = 1;
            que.push((node){k, t.steps + i + 1});
        }
    }
    return ;
}

int main(){
    cin >> n;
    bfs(1);
    return 0;
}