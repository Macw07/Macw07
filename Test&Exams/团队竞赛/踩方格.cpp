#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, total;
int memo[55][55];
int vis[55][55];

int dfs(int x, int y, int steps){
    if (steps == n){
        return memo[x][y] = 1;
    }
    int a=0, b=0, c=0;
    if (!vis[x+1][y]){
        vis[x+1][y] = 1;
        a = dfs(x+1, y, steps+1);
        vis[x+1][y] = 0;
    }
    if (!vis[x][y+1]){
        vis[x][y+1] = 1;
        b = dfs(x, y+1, steps+1);
        vis[x][y+1] = 0;
    }
    if (!vis[x][y-1]){
        vis[x][y-1] = 1;
        c = dfs(x, y-1, steps+1);
        vis[x][y-1] = 0;
    }
    memo[x][y] = a + b + c;
    return memo[x][y];
}

int main(){
    cin >> n;
    memset(memo, -1, sizeof memo);
    vis[23][0] = 1;
    total = dfs(23, 0, 0);
    cout << total << endl;
    return 0;
}