#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e6+5;

struct node{
    int to;  // 记录终点
    int next;  // 记录是否有下一条连通的边（边的编号）
    int weight;
} edge[2*N];  // 边集数组
int vertex[N];  // 顶点数组
int v, e, ei = 1;  // ei: 边集数组的初始下标

// 建图
void add(int v1, int v2, int weight){  // v1: 起点，v2: 终点
    edge[ei].to = v2;
    edge[ei].next = vertex[v1];
    edge[ei].weight = weight;
    vertex[v1] = ei++;
    return ;
}

int main(){
    cin >> v >> e;
    for (int i=1; i<=e; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;  // 输入一条边
        add(v1, v2, w);
    }
    return 0;
}