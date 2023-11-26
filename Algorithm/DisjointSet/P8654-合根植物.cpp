#include <iostream>
#include <set>
using namespace std;

const int MAXN = 1e6 + 5;
int a, b;
int n, m, k, ans;
set<int> s;
int parent[MAXN];

int find(int x){
    if (parent[x] == x) return x;
    int t = find(parent[x]);
    return parent[x] = parent[t];
}

void unionSet(int a, int b){
    int t1 = find(a);
    int t2 = find(b);
    parent[t1] = t2;
    return ;
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    for (int i=1; i<=n*m; i++) parent[i] = i;
    while(k--){
        scanf("%d %d", &a, &b);
        unionSet(a, b);
    }
    for (int i=1; i<=n*m; i++) s.insert(find(i));
    printf("%lu\n", s.size());
    return 0;
}