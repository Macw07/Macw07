#include <iostream>
#include <algorithm>
using namespace std;

// 搞了半天n和m写反了。

const int MAXN = 1e3 + 5;
int n, m;
int parent[MAXN];
struct node{
    int x;
    int y;
    int t;
} arr[100005];

inline bool cmp(node a, node b){return a.t <= b.t;}

int find(int x){
    if (parent[x] == x) return x;
    int t = find(parent[x]);
    return parent[x] = t;
}

void unionSet(int x, int y){
    int a = find(x);
    int b = find(y);
    parent[a] = parent[b];
    return ;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) parent[i] = i;
    for (int i=1; i<=m; i++) scanf("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].t);
    sort(arr+1, arr+1+m, cmp);
    for (int i=1; i<=m; i++){
        unionSet(arr[i].x, arr[i].y);
        int t = find(1);
        bool flag = true;
        for (int i=2; i<=n; i++){
            int t2 = find(i);
            if (t2 != t) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << arr[i].t << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}