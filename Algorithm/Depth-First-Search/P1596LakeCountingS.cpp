#include <iostream>
using namespace std;

int n, m;
char arr[105][105];
int dx[] = {0, 1, 0, -1, -1, -1, 1, 1};
int dy[] = {1, 0, -1, 0, -1, 1, -1, 1};

void dfs(int x, int y){
    // 将自己设为已访问节点
    arr[x][y] = '.';
    // 八个方向的遍历
    for (int i=0; i<8; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        // 舍弃
        if(cx > n || cy > m || cx < 1 || cy < 1 || arr[cx][cy] == '.') continue;
        dfs(cx, cy);
    }
    return;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        string s;
        cin >> s;
        for (int j=1; j<=m; j++){
            arr[i][j] = s[j-1];
        }
    }
    int total = 0;  // 记录水坑的数量
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            // 如果没有被访问过相邻的水坑
            if (arr[i][j] == 'W'){
                total++;
                dfs(i, j);
            }
        }
    }
    cout << total << endl;
    return 0;
}