#include <iostream>
#include <algorithm>
using namespace std;

int n;
string str = "yizhong";
char arr[105][105];
int check[105][105];  // 染色区块
// 八个递归的方向
int dx[] = {0, 1, 0, 1, -1, 0, -1, 1, -1};
int dy[] = {0, 0, 1, 1, 0, -1, -1, -1, 1};

bool render(int x, int y, int direction, int total){   
    int nx = x + dx[direction];
    int ny = y + dy[direction];
    if (arr[nx][ny] == str[total+1]){
        check[nx][ny] += 1;
        if (total == 5) return true;
        bool flag = render(nx, ny, direction, total+1);
        if (flag == false) check[nx][ny] -= 1; 
        return flag;
    }
    return false;
}

void dfs(int x, int y){
    for (int i=0; i<8; i++) {
        if (render(x, y, i, 0)) check[x][y] = 1;
    }
    return ;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (check[i][j] == 0 && arr[i][j] == 'y'){
                // 说明还没有被染过色，所以可以进行递归。
                dfs(i, j);
            }
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (check[i][j]) cout << arr[i][j];
            else cout << '*';
        }
        cout << endl;
    }
    return 0;
}