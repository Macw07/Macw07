#include <iostream>
using namespace std;

int flag = 0;
int vis[3][3][15];  // 表示第i, j个九宫格的i是否被使用过。
int horizontal[10][15];  // 表示每一行的数字i是否被使用过。
int vertical[10][15];  // 表示每一列的数字i是否被使用过。
char map[10][10];
char original[10][10];
char ans[10][10];

void dfs(int x, int y){
    if (y == 9){
        y = 0;
        x += 1;
    }
    if (x == 9){
        if (flag >= 1){
            for (int i=0; i<9; i++) cout << original[i] << endl;
            exit(0);
        }
        flag += 1;
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++){
                ans[i][j] = map[i][j];
            }
        }
        return ;
    }
    if (map[x][y] != '.'){
        dfs(x, y + 1);
        return ;
    }
    for (int i=1; i<=9; i++){
        if (vis[x/3][y/3][i] || vertical[y][i] || horizontal[x][i]) continue;
        vis[x/3][y/3][i] = 1;
        vertical[y][i] = 1;
        horizontal[x][i] = 1;
        map[x][y] = i + '0';
        dfs(x, y+1);
        map[x][y] = '.';
        vis[x/3][y/3][i] = 0;
        vertical[y][i] = 0;
        horizontal[x][i] = 0;
    }
    return ;
}

bool check(int i, int j){
    if (vis[i/3][j/3][map[i][j] - '0'] == 1) return false;
    if (horizontal[i][map[i][j] - '0'] == 1) return false;
    if (vertical[j][map[i][j] - '0'] == 1) return false;
    return true;
}

int main(){
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            cin >> map[i][j];
            original[i][j] = map[i][j];
            if (map[i][j] != '.'){
                if (!check(i, j)){
                    cout << "ERROR" << endl;
                    exit(0);
                }
                vis[i/3][j/3][map[i][j] - '0'] = 1;
                horizontal[i][map[i][j] - '0'] = 1;
                vertical[j][map[i][j] - '0'] = 1;
            }
        }
    }
    dfs(0, 0);  // 按照每一位来深搜。
    if (flag == 1) for (int i=0; i<9; i++) cout << ans[i] << endl;
    else cout << "ERROR" << endl;
    return 0;
}