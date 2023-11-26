#include <iostream>
using namespace std;

int cnt = 0;
char map[10][10];
int vis[3][3][15]; 
int horizontal[10][15];  
int vertical[10][15];

// 判断一个点是否合法。
bool check(int i, int j){
    int t = map[i][j] - '0';
    if (vis[i/3][j/3][t] == 1) return false;
    if (horizontal[i][t] == 1) return false;
    if (vertical[j][t] == 1) return false;
    return true;
}

bool double_check(int x, int y, int num){
    // 查看x, y所在的九宫格是否其他位置都被占满了，或无法放置数字num。
    int x_begin = x / 3, y_begin = y / 3;
    if (vis[x_begin][y_begin][num]) return false;
    x_begin *= 3, y_begin *= 3;
    for (int i=x_begin; i<x_begin+3; i++){
        for (int j=y_begin; j<y_begin+3; j++){
            if (i == x && j == y) continue;
            if (!(map[i][j] != '.' || horizontal[i][num] || vertical[j][num])) {
                return false;
            }
        }
    }
    map[x][y] = num + '0';
    if (check(x, y)) return true;
    map[x][y] = '.';
    return false;
}

int main(){
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            cin >> map[i][j];
            if (map[i][j] != '.'){
                if (!check(i, j)){
                    cout << "ERROR" << endl;
                    return 0;
                }
                int t = map[i][j] - '0';
                vis[i/3][j/3][t] = 1;
                horizontal[i][t] = 1;
                vertical[j][t] = 1;
            }
        }
    }
    int it = 1;
    cout << double_check(1, 5, 9) << endl;
    while(true && it--){
        bool flag = 1;
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                // 找每一个位置是否可以通过交叉影线法放入一个数字。
                if (map[i][j] != '.') continue;
                for (int k=1; k<=9; k++){
                    if (double_check(i, j, k)){
                        cnt++;
                        vis[i/3][j/3][k] = 1;
                        horizontal[i][k] = 1;
                        vertical[j][k] = 1;
                        flag = 0;
                        for (int i=0; i<9; i++) cout << map[i] << endl;
                        return 0;
                        break;
                    }
                }
            }
        }
        if (flag) break;
    }
    if (cnt) for (int i=0; i<9; i++) cout << map[i] << endl;
    else cout << "ERROR" << endl;
    return 0;
}

/*
123......
456......
78......9
.........
.........
.........
.........
.........
.........
*/