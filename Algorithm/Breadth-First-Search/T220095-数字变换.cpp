#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int k;
struct node{
    int value;
    int steps;
};
queue<node> que;
int vis[100005];

void bfs(){
    vis[0] = 1;
    que.push((node){0, 0});
    while(!que.empty()){
        node t = que.front();
        if (t.value == k){
            cout << t.steps << endl;
            return ;
        }
        if (!vis[t.value+1]) {
            vis[t.value] = 1;
            que.push((node){t.value+1, t.steps+1});
        }
        if (t.value*2 <= 100005 && !vis[t.value*2]) {
            vis[t.value*2] = 1;
            que.push((node){t.value*2, t.steps+1});
        }
        que.pop();
    }
    return ;
}

int main(){
    cin >> k;
    bfs();
    return 0;
}