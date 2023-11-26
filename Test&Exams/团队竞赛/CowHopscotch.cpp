#include <iostream>
using namespace std;

int n, m;
long long cnt;
char arr[30][30];

void dfs(int x, int y, char color){
    if (x == n && y == m){
        cnt++;
        return ;
    }
    for (int i=x+1; i<=n; i++){
        for (int j=y+1; j<=m; j++){
            if (color != arr[i][j]){
                dfs(i, j, arr[i][j]);
            }
        }
    }
    return ;
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    dfs(1, 1, arr[1][1]);
    cout << cnt << endl;
    return 0;
}