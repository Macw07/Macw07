#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5+15;
int n, m, p;
int Graph[MAXN];
int visited[MAXN];

int finding(int current_show, int depth){
    if (visited[current_show]) return -1;  // 图环路
    if (Graph[current_show] == 0) return depth;  // 保存答案
    visited[current_show] = true;
    return finding(Graph[current_show], depth+1);
}   

int main(){
    scanf("%d %d %d\n", &n, &m, &p);
    for (int i=1; i<=n; i++){
        int v1, v2;
        cin >> v1 >> v2;
        if (Graph[v2]) continue;
        Graph[v2] = v1;
    }
    printf("%d", finding(p, 0));
    return 0;
}