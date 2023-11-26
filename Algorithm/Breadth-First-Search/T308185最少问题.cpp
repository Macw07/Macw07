#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, k;

struct node{
    int num;
    int steps;
};

queue<node> que;
bool vis[50000005];

void bfs(){
    vis[n] = 1;
    que.push((node){n, 0});

    while(!que.empty()){
        node now = que.front();
        // 判断是否是结果
        if (now.num == k){
            cout << now.steps << endl;
            return;
        }

        // 三种情况添加
        if (now.num < k && vis[now.num+1] == 0){
            vis[now.num+1] = 1;
            que.push((node){now.num+1, now.steps+1});
        }
        if (now.num >= 1 && vis[now.num-1] == 0){
            vis[now.num-1] = 1;
            que.push((node){now.num-1, now.steps+1});
        }
        if (now.num*2 < 50000005 && vis[now.num*2] == 0){
            vis[now.num*2] = 1;
            que.push((node){now.num*2, now.steps+1});
        }
        que.pop();
    }
}

int main(){
    cin >> n >> k;
    bfs();
    return 0;
}