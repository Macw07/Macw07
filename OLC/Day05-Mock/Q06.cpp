#include <iostream>
#include <algorithm>
using namespace std;

int n, m, tmp;
int ans1, ans2;
int arr[55][55];
int vis[55][55];
int dx[] = {0, 0, -1, 0, 1};
int dy[] = {0, -1, 0, 1, 0};

string check(int x, int y){
    string str = "0";
    int num = arr[x][y];
    while(num){
        str += ((num % 2) + '0');
        num /= 2;
    }
    while(str.size() < 5) str += '0';
    return str;
}

void dfs(int x, int y){
    string str = check(x, y);
    for (int i=1; i<=4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (str[i] == '1') continue;
        if (cx < 1 || cy < 1 || cx > n || cy > m || vis[cx][cy]) continue;  // 不合法的边界。
        tmp += 1;
        vis[cx][cy] = 1;
        dfs(cx, cy);
    }
    return ;
}   

int main(){
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    // 联通分量问题。
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (vis[i][j]) continue;
            vis[i][j] = 1;
            ans1++;
            tmp = 1;
            dfs(i, j);
            ans2 = max(ans2, tmp);
        }
    }
    cout << ans1 << endl << ans2 << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}