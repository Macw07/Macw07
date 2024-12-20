# 迷宫搜寻 - 深度优先搜索算法的求解思路
> 找到所有的可行解

### 什么是深度优先搜索?

一句话解释的话: **不撞南墙不回头**。
深度优先搜索通过递归算法的思路一直沿着一个方向进行搜索,直到走头无路的时候才会换一个方向进行搜索。
一般情况来说，深度优先搜索(DFS)适用于寻找所有的可行解，相对来说着最短路径用广度优先搜索(BFS)可能会更好。

### 程序实现过程 + 注释

本代码适用于基本的迷宫搜寻.
> 一个迷宫由 n 行 m 列格子组成,有的格子里有障碍物，不能走；有的格子是空地，可以走。
> 给定一个迷宫，求从左上角走到右下角是否能走通。

``` c++
#include <iostream>
#include <algorithm>
using namespace std;

int ans = 0;  // 负责记录解的数量
int n, m;  // 定义n和m,n和m既可以表示图的大小,也可以表示成图的终点坐标
char map[50][50];  // 创建一个char类型的二维地图数组,负责记录图中的元素
int dx[4] = {0, 1, 0, -1};  // x坐标的偏移
int dy[4] = {1, 0, -1, 0};  // y坐标的偏移
int vis[50][50];  // 用于记录坐标是否被访问过了

// 创建一个函数,进行深度优先搜索找出所有的解
void dfs(int x, int y){  // 函数有两个参数,分别是拓展到当前点的x和y坐标
    // 递归的结束条件: 当当前的坐标等于目标坐标时,结束递归
    if (x == n && y == m) {ans++; return;};
    // 顺时针依次往上下左右四个方向进行拓展
    for (int i=0; i<4; i++){
        // cx, cy表示下一个拓展的位置
        int cx = x + dx[i];
        int cy = y + dy[i];
        // 边界处理
        if (cx > n || cy > m || cx < 1 || cy < 1) continue;
        // 如果要处理的位置没有被访问过且不是障碍物,那就进行访问
        if (vis[cx][cy] == 0 && map[cx][cy] != '#'){
            vis[cx][cy] = 1;  // 将节点标记为已访问
            dfs(cx, cy);  // 递归下一个节点,重复执行判断上下左右的节点
            vis[cx][cy] = 0;  // 当递归完成后,撤销对节点的操作
        }
    }
}
int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> map[i][j];  // 循环读入数组的每一个元素
    dfs(1, 1);  // 调用递归函数,初始的坐标是(1,1)
    cout << ans << endl;  // 输出结果
    // 如果输出是否可以走通
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
```