#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

/*
考虑三种情况：
    1. 牛走人不走
    2. 人走牛不走
    3. 人走牛也走
dp[i][j]表示John走到第i步，Bessie走到第j步消耗的最少能量。
fx, fy, cx, cy的i表示走到每个人走到第i步的坐标。
*/

const int MAX_ = 1005;
int n, m, dp[MAX_][MAX_];
string npath, mpath;
int dx[MAX_] = {0, 1, 0, -1};
int dy[MAX_] = {1, 0, -1, 0};
int fx[MAX_], fy[MAX_], cx[MAX_], cy[MAX_];

inline int direction(char c){
    if (c == 'N') return 0;
    if (c == 'E') return 1;
    if (c == 'S') return 2;
    return 3;
}

inline int distance(int fx, int fy, int cx, int cy){
    return (fx-cx) * (fx-cx) + (fy - cy) * (fy - cy);
}

int main(){
    cin >> n >> m;
    cin >> fx[0] >> fy[0] >> cx[0] >> cy[0];
    cin >> npath >> mpath;
    npath = " " + npath;
    mpath = " " + mpath;
    
    // 预处理，处理Farmer和Bessie每一步的位置。
    for (int i=1; i<=n; i++){
        fx[i] = fx[i-1] + dx[direction(npath[i])];
        fy[i] = fy[i-1] + dy[direction(npath[i])];
    }
    for (int i=1; i<=m; i++){
        cx[i] = cx[i-1] + dx[direction(mpath[i])];
        cy[i] = cy[i-1] + dy[direction(mpath[i])];
    }

    // 初始化操作 + 奶牛和农场主一直没动所消耗的能量。
    memset(dp, 0x7f, sizeof dp);
    dp[0][0] = 0;  // 表示一开始奶牛和农场主不通讯，通讯的代价为0。
    for(int j=1; j<=m; j++){  // 农场主不动。
        dp[0][j] = dp[0][j-1] + distance(fx[0], fy[0], cx[j], cy[j]);
    }
    for (int i=1; i<=n; i++){  // 奶牛不动。
        dp[i][0] = dp[i-1][0] + distance(fx[i], fy[i], cx[0], cy[0]);
    }
    

    // 动态规划，遍历n和m求出最优解。
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            int dis = distance(fx[i], fy[i], cx[j], cy[j]);
            dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + dis;
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}