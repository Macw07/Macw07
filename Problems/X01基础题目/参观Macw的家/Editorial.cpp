#include <iostream>
using namespace std;

int x, y;
int n, m;
int arr_x[1005][1005];
int arr_y[1005][1005];
int vis[1005][1005];

int main(){
    // freopen("testcase008.in", "r", stdin);
    // freopen("testcase008.out", "w", stdout);
    cin >> n >> m >> x >> y;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr_x[i][j] >> arr_y[i][j];
        }
    }
    int cx = x, cy = y;
    while(true){
        cout << cx << " " << cy << endl;
        vis[cx][cy] = 1;
        int nx = arr_x[cx][cy];
        int ny = arr_y[cx][cy];
        cx = nx, cy = ny;
        if (vis[cx][cy]){
            break;
        }
    }
    return 0;
}