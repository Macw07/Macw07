#include <iostream>
#include <algorithm>
using namespace std;

int total = 0;
char map[15][15];
int vis[15][15][15][15];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int fx, fy, fdir;
int cx, cy, cdir;

bool check(int nx, int ny){
    return nx >= 1 && nx <= 10 && ny >= 1 && ny <= 10;
}

int main(){
    for (int i=1; i<=10; i++){
        for (int j=1; j<=10; j++){
            cin >> map[i][j];
            if (map[i][j] == 'C'){
                cx = i, cy = j;
            }
            else if (map[i][j] == 'F'){
                fx = i, fy = j;
            }
        }
    }
    vis[fx][fy][cx][cy] = 1;
    // 超级大模拟
    while((fx != cx || fy != cy)){
        // 判断障碍物
        total += 1;
        int nx = cx + dx[cdir];
        int ny = cy + dy[cdir];
        if (!check(nx, ny) || map[nx][ny] == '*'){
            cdir += 1;
            cdir %= 4;
        } else if(check(nx, ny) && map[nx][ny] != '*'){
            cx = nx, cy = ny;
        }
        nx = fx + dx[fdir];
        ny = fy + dy[fdir];
        if (!check(nx, ny) || map[nx][ny] == '*'){
            fdir += 1;
            fdir %= 4;
        } else if (check(nx, ny) && map[nx][ny] != '*'){
            fx = nx, fy = ny;
        }
        vis[fx][fy][cx][cy] += 1;
        if (vis[fx][fy][cx][cy] > 4){
            cout << 0 << endl;
            return 0;
        }
    }
    cout << total << endl;
    return 0;
}