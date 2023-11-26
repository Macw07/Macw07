#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 500000 + 5;
struct node{
    int max_v;
    int min_v;
};
int n, m;
int t, x, y;
int arr[MAXN];
node tree[MAXN << 2];

void pushUp(int root){
    tree[root].max_v = max(tree[root << 1].max_v, tree[root << 1|1].max_v);
    tree[root].min_v = min(tree[root << 1].min_v, tree[root << 1|1].min_v);
    return ;
}

void build(int l, int r, int root){
    if (l == r){
        tree[root].max_v = arr[l];
        tree[root].min_v = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, root << 1);
    build(mid+1, r, root << 1|1);
    pushUp(root);
    return ;
}

void update(int l, int r, int k, int v, int root){
    if (l == r){
        tree[root].max_v = v;
        tree[root].min_v = v;
        return ;
    }
    int mid = (l + r) >> 1;
    if (k <= mid) update(l, mid, k, v, root << 1);
    else update(mid + 1, r, k, v, root << 1|1);
    pushUp(root);
    return ;
}

int queryMax(int l, int r, int L, int R, int root){
    int ans = -0x7f7f7f7f;
    if (L <= l && r <= R) return tree[root].max_v;
    int mid = (l + r) >> 1;
    if (L <= mid) ans = max(ans, queryMax(l, mid, L, R, root << 1));
    if (R > mid) ans = max(ans, queryMax(mid+  1, r, L, R, root << 1|1));
    return ans;
}

int queryMin(int l, int r, int L, int R, int root){
    int ans = 0x7f7f7f7f;
    if (L <= l && r <= R) return tree[root].min_v;
    int mid = (l + r) >> 1;
    if (L <= mid) ans = min(ans, queryMin(l, mid, L, R, root << 1));
    if (R > mid) ans = min(ans, queryMin(mid + 1, r, L, R, root << 1|1));
    return ans;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) scanf("%d", &arr[i]);

    build(1, n, 1);

    while(m--){
        scanf("%d %d %d", &t, &x, &y);
        if (t == 1) update(1, n, x, y, 1);
        else if (t == 2){
            int ans = queryMax(1, n, x, y, 1);
            printf("%d\n", ans);
        } else{
            int ans = queryMin(1, n, x, y, 1);
            printf("%d\n", ans);
        }
    }
    return 0;
}