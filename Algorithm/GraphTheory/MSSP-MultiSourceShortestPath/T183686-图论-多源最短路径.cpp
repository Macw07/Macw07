#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*floyd算法是一个经典的动态规划算法。用通俗的语言来描述的话，首先我们的目标是寻找从点i到点j的最短路径。
从动态规划的角度看问题，我们需要为这个目标重新做一个诠释（这个诠释正是动态规划最富创造力的精华所在）

从任意节点i到任意节点j的最短路径不外乎2种可能，1是直接从i到j，2是从i经过若干个节点k到j。
所以，我们假设Dis(i,j)为节点u到节点v的最短路径的距离，对于每一个节点k，
我们检查Dis(i,k) + Dis(k,j) < Dis(i,j)是否成立，如果成立，证明从i到k再到j的路径比i直接到j的路径短，
我们便设置Dis(i,j) = Dis(i,k) + Dis(k,j)，这样一来，当我们遍历完所有节点k，Dis(i,j)中记录的便是i到j的最短路径的距离。*/

int n, m, q;
int map[105][105];

int main(){
    cin >> n >> m >> q;
    for (int i=1; i<=100; i++){
        for (int j=1; j<=100; j++){
            map[i][j] = 0x7f7f7f;
        }
        map[i][i] = 0;
    }

    for (int i=1; i<=m; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        map[v1][v2] = w;
        map[v2][v1] = w;
    }

    for (int k=1; k<=n; k++){  // 遍历每一个中转节点
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    for (int j=1; j<=q; j++){
        int v1, v2;
        cin >> v1 >> v2;
        cout << map[v1][v2] << endl;
    }
    return 0;
}