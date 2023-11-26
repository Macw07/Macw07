#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

/*
用dijkstra+堆优化 打暴力的同学可能会发现无论如何暴力拿分都有1个点t掉，这里是一处此题很奇妙的地方。让我们来算一算这个暴力算法的时间复杂度 首先是dijkstra+堆优化的最短路复杂度 （n+m）logn【按最大数据大约是35000次】 然后因为我们走了（m+1次）所以是 （m+1）（n+m）logn 我们会发现，这个算法在题目的范围内破亿了，这也就是dijkstra+堆优化t掉的原因。
但是由于这道题n的范围极其之小，我们会发现最原始的dijkstra的时间复杂度（n^2） 我们扫一遍查找离起点最近的未遍历的点，再扫一遍，用此点来进行松弛操作【更新最短路】 那么大致的时间复杂度就是（2*n^2）我们再进行（m+1）次 【按最大数据来计算则大概刚好到1亿，算是勉强挨边】 次数要小于堆优化过的 （所以这道题用原始版dijkstra是可以过的）
*/

const int MAXM = 5005;
int n, m, ei, ans;
int dis[105], vis[105];
int Graph[105][105];
int x[6005], y[6005], o;  // 用于记录“要修改”的每条边

void dijkstra(int origin){
    for (int i=1; i<=n; i++){
        vis[i] = 0;
        dis[i] = 0x7f7f7f7f;
    }
    dis[origin] = 0;
    for (int i=1; i<n; i++){
        int minn = 0x7f7f7f7f, t;
        for (int j=1; j<=n; j++){
            if (!vis[j] && dis[j] < minn){
                t = j;
                minn = dis[j];
            }
        }
        vis[t] = 1;
        for (int j=1; j<=n; j++) {
            if (vis[j]) continue;
            if (dis[t] + Graph[t][j] < dis[j]){
                dis[j] = dis[t] + Graph[t][j];
            }
        }
    }
    return ;
}

int main(){
    scanf("%d %d", &n, &m);

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            Graph[i][j] = 0x7f7f7f7f;
        }
    }

    for (int i=1; i<=m; i++){
        int v1, v2, w;
        scanf("%d %d %d", &v1, &v2, &w);
        Graph[v1][v2] = Graph[v2][v1] = w;
        x[++o] = v1;
        y[o] = v2;
    }

    dijkstra(1);
    int t_ans = dis[n];
    int ans = 0;
    for (int i=1; i<=o; i++){
        Graph[x[i]][y[i]] *= 2;
        Graph[y[i]][x[i]] *= 2;
        ans = max(ans, dis[n] - t_ans);
        dijkstra(1);
        Graph[x[i]][y[i]] /= 2;
        Graph[y[i]][x[i]] /= 2;
    }
    printf("%d\n", ans);
    return 0;
}