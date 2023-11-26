#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, a, b;
int arr[1005];
bool flag, vis[1005];

struct node{
    int current;
    long steps;
};

queue<node> que;

void bfs(){
    que.push((node){a, 0});
    vis[a] = 1;
    while(que.size()){
        node top = que.front();
        if (top.current == b){
            cout << top.steps << endl;
            flag = 1;
            return ;
        }
        // 两个判断：去楼上，去楼下
        int up = top.current + arr[top.current];
        int down = top.current - arr[top.current];
        if (up <= n && !vis[up]) {
            vis[up] = 1;
            que.push((node){up, top.steps+1});
        }
        if (down >= 1 && !vis[down]){
            vis[down] = 1;
            que.push((node){down, top.steps+1});
        }
        que.pop();
    }
    return ;
}

int main(){
    cin >> n >> a >> b;
    for (int i=1; i<=n; i++) cin >> arr[i];
    bfs();
    if (flag == 0) cout << -1 << endl;
    return 0;
}