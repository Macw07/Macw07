#include <iostream>
using namespace std;

int n, m, ei;
int isPossible[100005];
int vertex[100005];
struct perEdge{
    int to;
    int next;
} edge[100005];

void add(int v1, int v2){
    ei += 1;
    edge[ei].next = vertex[v1];
    edge[ei].to = v2;
    vertex[v1] = ei;
    return ;
}

void dfs(int v){
    int index = vertex[v];
    while(index){
        int u = edge[index].to;
        if (isPossible[u] == 0){
            isPossible[u] = 1;
            dfs(u);
        }
        index = edge[index].next;
    } 
    return ;
}

/*
从第一位巫师开始遍历图，如果一个巫师u可以打败第一位巫师，则这个巫师可以拿到魔杖。
同理，所有可以打败巫师u的巫师都有机会拿到魔杖。
*/

int main(){
    scanf("%d %d", &n, &m);
    while(m--){
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        add(v2, v1);  // 反向建图。
    }
    // 如果一号巫师没有进行任何一场决斗的话，则没有其他巫师可以拿到魔杖。
    if (vertex[1] == 0){
        cout << 1;
        for (int i=2; i<=n; i++) cout << 0;
        return 0;
    }
    dfs(1);
    for (int i=1; i<=n; i++) cout << isPossible[i];
    return 0;
}