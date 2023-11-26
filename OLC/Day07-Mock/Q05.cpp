#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, a, b;
bool flag = false;
int arr[250], vis[250];

struct node{
    int x;
    int steps;
};

void bfs(){
    queue<node> que;
    que.push((node){a, 0});
    vis[a] = 1;
    
    while(!que.empty()){
        node t = que.front();
        que.pop();
        if (t.x == b){
            cout << t.steps << endl;
            flag = true;
            return ;
        }

        int before = t.x - arr[t.x];
        int after = t.x + arr[t.x];

        if (before >= 1 && before <= 200 && vis[before] == 0) {
            vis[before] = 1;
            que.push((node){before, t.steps + 1});
        }
        else if (after >= 1 && after <= 200 && vis[after] == 0){
            vis[after] = 1;
            que.push((node){after, t.steps + 1});
        }
    }
    return ;
}

int main(){
    freopen("bear.in", "r", stdin);
    freopen("bear.out", "w", stdout);
    cin >> n >> a >> b;
    for (int i=1; i<=n; i++) cin >> arr[i];
    bfs();
    if (!flag) cout << -1 << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}