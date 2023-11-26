#include <iostream>
#include <algorithm>
using namespace std;

int map[5][5];
int vis[5][5];

bool check(){
    for (int i=1; i<=3; i++){
        for (int j=1; j<=3; j++){
            if (map[i][j] == 0) return false;
        }
    }
    return true;
}

void transform(int x, int y){
    map[x][y] ^= 1;
    map[x+1][y] ^= 1;
    map[x-1][y] ^= 1;
    map[x][y-1] ^= 1;
    map[x][y+1] ^= 1;
}

void dfs(int steps){
    if (check()) {
        cout << steps << endl;
        exit(0);
    }
    for (int i=1; i<=3; i++){
        for (int j=1; j<=3; j++){
            if (vis[i][j]) continue;
            vis[i][j] = 1;
            transform(i, j);
            dfs(steps+1);
            transform(i, j);
            vis[i][j] = 0;
        }
    }
    return ;
}

int main(){
    for (int i=1; i<=3; i++){
        for (int j=1; j<=3; j++){
            cin >> map[i][j];
        }
    }
    dfs(0);
    return 0;
}