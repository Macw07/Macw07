#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char a, b;
int new_a, new_b;
int p = 0x7f7f7f, r;
struct node{
    int v;
    int w;
};
int temp[10], vis[15][15];
int ans[10];
vector<node> G[100];

void dfs(int current, int path, int index){
    // cout << 1 << endl;
    if (path > p) return ;
    if (current == new_b){
        if (path < p){
            // cout << 1 << endl;
            for (int i=0; i<index; i++) ans[i] = temp[i];
            p = path;
            r = index;
        }
        return ;
    }
    for (int i=0; i<G[current].size(); i++) {
        // cout << 2 << endl;
        if (vis[current][G[current][i].v] || vis[G[current][i].v][current]) continue;
        vis[current][G[current][i].v] = 1;
        vis[G[current][i].v][current] = 1;
        temp[index] = G[current][i].v;
        dfs(G[current][i].v, path + G[current][i].w, index+1);
        vis[current][G[current][i].v] = 0;
        vis[G[current][i].v][current] = 0;
    }
    return ;
}

int main(){
    cin >> a >> b;
    new_a = a - 'a', new_b = b - 'a';
    G[0].push_back((node){1, 1});
    G[0].push_back((node){2, 1});
    G[1].push_back((node){4, 3});
    G[2].push_back((node){3, 1});
    G[3].push_back((node){4, 1});
    G[3].push_back((node){5, 2});
    G[4].push_back((node){6, 1});
    G[5].push_back((node){6, 1});

    G[1].push_back((node){0, 1});
    G[2].push_back((node){0, 1});
    G[4].push_back((node){1, 3});
    G[3].push_back((node){2, 1});
    G[4].push_back((node){3, 1});
    G[5].push_back((node){3, 2});
    G[6].push_back((node){4, 1});
    G[6].push_back((node){5, 1});

    vis[new_a][new_a] = 1;
    dfs(new_a, 0, 0);
    if (r){
        cout << a;
        for (int i=0; i<r; i++) cout << char(ans[i]+'a');
    }
    return 0; 
}