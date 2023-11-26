#include <iostream>
using namespace std;

const int MAXN = 1e4 + 5;
int z, x, y;
int n, m, parent[MAXN];

int find(int x){
    if (parent[x] == x) return x;
    int t = find(parent[x]);
    return parent[x] = t;  
}

// 将集合X与集合Y合并。
void unionSet(int x, int y){
    int x_parent = find(x);
    int y_parent = find(y);
    parent[x_parent] = parent[y_parent];
    return ;    
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) parent[i] = i;
    for (int i=1; i<=m; i++){
        scanf("%d %d %d", &z, &x, &y);
        if (z == 1) unionSet(x, y);
        else{
            int t1 = find(x);
            int t2 = find(y);
            if (t1 == t2) printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}
