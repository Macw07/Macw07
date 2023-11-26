#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char arr[10][10];
bool flag = 0;
int total = 0;

bool horizontal_vis[10][10];
bool vertical_vis[10][10];
bool ntn_vis[3][3][10];

void dfs(int x, int y){
    if (flag) return ;
    if (y == 9){
        x = x + 1;
        y = 0;
    }
    if (x == 9){
        for (int i=0; i<9; i++) cout << arr[i] << endl;
        flag = 1;
        return ;
    }

    if (arr[x][y] != '.'){
        dfs(x, y+1);
        return ;
    }
    
    for (int k=1; k<=9; k++){
        if (horizontal_vis[x][k]) continue;
        if (vertical_vis[y][k]) continue;
        if (ntn_vis[x/3][y/3][k]) continue;

        horizontal_vis[x][k] = 1;
        vertical_vis[y][k] = 1;
        ntn_vis[x/3][y/3][k] = 1;

        arr[x][y] = k + '0';
        dfs(x, y+1);
        arr[x][y] = '.';

        horizontal_vis[x][k] = 0;
        vertical_vis[y][k] = 0;
        ntn_vis[x/3][y/3][k] = 0;
    }
    return ;
}

int main(){
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++){
            cin >> arr[i][j];
            if (arr[i][j] != '.'){
                int t = arr[i][j] - '0';
                horizontal_vis[i][t] = 1;
                vertical_vis[j][t] = 1;
                ntn_vis[i/3][j/3][t] = 1;
            }
        }
    }
    dfs(0, 0);
    return 0;
}