#include <iostream>
using namespace std;

const int MAXN = 5e3 + 5;
int n, m, k;
int parent[MAXN];

int find(int x){
    if (parent[x] == x) return x;
    int t = find(parent[x]);
    return parent[x] = t;
}

void unionSet(int a, int b){
    int t1 = find(a);
    int t2 = find(b);
    parent[t1] = parent[t2];
    return ;
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for (int i=1; i<=n; i++) parent[i] = i;
    for (int i=1; i<=m; i++){
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        unionSet(t1, t2);
    }
    for (int i=1; i<=k; i++){
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        int a = find(t1);
        int b = find(t2);
        if (a == b) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}