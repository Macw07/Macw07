#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
struct node{
    int bottle1;
    int bottle2;
    vector<string> path;
    int steps;
};
bool vis[105][105];
queue<node> que;

void bfs(){
    que.push((node){0, 0});
    vis[0][0] = 1;
    while(!que.empty()){
        node front = que.front();
        if (front.bottle1 == k || front.bottle2 == k){
            cout << front.steps << endl;
            for (int i=0; i<front.path.size(); i++){
                cout << front.path[i] << endl;
            }
            exit(0);
        }

        // 六种方式
        if (!vis[n][front.bottle2]){
            que.push((node){n, front.bottle2, front.path, front.steps+1});
            que.back().path.push_back("FILL(1)");
            vis[n][front.bottle2] = 1;
        }
        if (!vis[front.bottle1][m]){
            que.push((node){front.bottle1, m, front.path, front.steps+1});
            que.back().path.push_back("FILL(2)");
            vis[front.bottle1][m] = 1;
        }
        if (!vis[0][front.bottle2]){
            que.push((node){0, front.bottle2, front.path, front.steps+1});
            que.back().path.push_back("DROP(1)");
            vis[0][front.bottle2] = 1;
        }
        if (!vis[front.bottle1][0]){
            que.push((node){front.bottle1, 0, front.path, front.steps+1});
            que.back().path.push_back("DROP(2)");
            vis[front.bottle1][0] = 1;
        }
        if (front.bottle1 + front.bottle2 > m){
            if (!vis[front.bottle1-(m-front.bottle2)][m]){
                que.push((node){front.bottle1-(m-front.bottle2), m, front.path, front.steps+1});
                que.back().path.push_back("POUR(1,2)");
                vis[front.bottle1-(m-front.bottle2)][m] = 1;
            }
        }
        if (front.bottle1 + front.bottle2 > n){
            if (!vis[n][front.bottle2-(n-front.bottle1)]){
                que.push((node){n, front.bottle2-(n-front.bottle1), front.path, front.steps+1});
                que.back().path.push_back("POUR(2,1)");
                vis[n][front.bottle2-(n-front.bottle1)] = 1;
            }
        }
        if (front.bottle1 + front.bottle2 <= m){
            if (!vis[0][front.bottle1 + front.bottle2]){
                que.push((node){0, front.bottle1 + front.bottle2, front.path, front.steps+1});
                que.back().path.push_back("POUR(1,2)");
                vis[0][front.bottle1 + front.bottle2] = 1;
            }
        }
        if (front.bottle1 + front.bottle2 <= n){
            if (!vis[front.bottle1 + front.bottle2][0]){
                que.push((node){front.bottle1 + front.bottle2, 0, front.path, front.steps+1});
                que.back().path.push_back("POUR(2,1)");
                vis[front.bottle1 + front.bottle2][0] = 1;
            }
        }
        que.pop();
    }
    return;
}

int main(){
    cin >> n >> m >> k;
    bfs();
    cout << "impossible" << endl;
    return 0;
}