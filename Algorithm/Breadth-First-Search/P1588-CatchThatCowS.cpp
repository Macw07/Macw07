#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int wi, ni;
int vis[100005];

struct node{int current; int steps; };

void bfs(){
    queue<node> que;
    que.push((node){wi, 0});
    while(!que.empty()){
        node front = que.front();
        que.pop();
        if (front.current == ni) {
            cout << front.steps << endl;;
            return;
        }
        if (front.current - 1 >= 0 && !vis[front.current-1]) {
            que.push((node){front.current-1, front.steps+1}); 
            vis[front.current-1] = 1;
        }
        if (front.current + 1 <= 100000 && !vis[front.current+1]) {
            que.push((node){front.current+1, front.steps+1}); 
            vis[front.current+1] = 1;
        }
        if (front.current * 2 <= 100000 && !vis[front.current*2]) {
            que.push((node){front.current*2, front.steps+1}); 
            vis[front.current*2] = 1;
        }

    }
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        memset(vis, 0, sizeof vis);
        cin >> wi >> ni;
        bfs();
    }
    return 0;
}