#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int a, b;
int map[105][105];

// 图的连通性;

int main(){
    // freopen("magic.in", "r", stdin);
    // freopen("magic.out", "w", stdout);
    cin >> n >> m;

    // floyd 初始化
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++){
            map[i][j] = 1000000;
        }
        map[i][i] = 0;
    }

    for (int i=1; i<=m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        map[v1][v2] = 1;  // 从v1到v2需要走一步路。
    }
    cin >> a >> b;

    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if (i == j) continue;
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    if (map[a][b] == 1000000) cout << -1 << endl;
    else cout << map[a][b] << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}