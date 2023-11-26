#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e6 + 5;
int n, m;
int t, x, y, z;
int tree[MAXN << 2];
int arr[MAXN];
int diff[MAXN];

/*
保证差分数组永远为正即可。
*/

void build(int l, int r, int root){
    if (l == r) {
        tree[root] = diff[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, root << 1);
    build(mid + 1, r, root << 1|1);
    tree[root] = min(tree[root << 1], tree[root << 1|1]);
    return ;
}

void update(int l, int r, int k, int v, int root){
    if (l == r){
        tree[root] += v;
        return ;
    }
    int mid = (l + r) >> 1;
    if (k <= mid) update(l, mid, k, v, root << 1);
    else update(mid + 1, r, k, v, root << 1|1);
    tree[root] = min(tree[root << 1], tree[root << 1|1]);
    return ;
}

int query(int l, int r, int L, int R, int root){
    int ans = 0x7f7f7f7f;
    if (L <= l && r <= R) return tree[root];
    int mid = (l + r) >> 1;
    if (L <= mid) ans = min(ans, query(l, mid, L, R, root << 1));
    if (R > mid) ans = min(ans, query(mid + 1, r, L, R, root << 1|1));
    return ans;
} 

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
        diff[i] = arr[i] - arr[i-1];
    }
    build(1, n+1, 1);
    while(m--){
        scanf("%d", &t);
        if (t == 1){
            scanf("%d %d %d", &x, &y, &z);
            update(1, n+1, x, z, 1);
            update(1, n+1, y+1, -z, 1);
        } else{
            scanf("%d %d", &x, &y);
            int ans = query(1, n+1, x+1, y, 1);
            if (ans >= 0) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}