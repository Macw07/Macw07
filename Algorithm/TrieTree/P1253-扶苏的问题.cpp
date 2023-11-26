#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 1e6+5;
const ll INF = 1e12;

int n, m;
int t, x, y, k;
ll arr[MAXN];
struct node{
    ll max;
    ll cover;
    ll add;
} tree[MAXN << 2];

void pushUp(int root){
    tree[root].max = max(tree[root << 1].max, tree[root << 1|1].max);
    return ;
}

void pushDown(int root){
    if (tree[root].cover != INF){
        tree[root << 1].add = 0;
        tree[root << 1|1].add = 0;
        tree[root << 1].cover = tree[root].cover;
        tree[root << 1|1].cover = tree[root].cover;
        tree[root << 1].max = tree[root].cover;
        tree[root << 1|1].max = tree[root].cover;
        tree[root].cover = INF;
    }
    if (tree[root].add){
        tree[root << 1].add += tree[root].add;
        tree[root << 1|1].add += tree[root].add;
        tree[root << 1].max += tree[root].add;
        tree[root << 1|1].max += tree[root].add;
        tree[root].add = 0;
    }
    return ;
}

void build(int l, int r, int root){
    if (l == r) {
        tree[root].max = arr[l];
        tree[root].cover = INF;
        tree[root].add = 0;
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, root << 1);
    build(mid + 1, r, root << 1|1);
    pushUp(root);
    return ;
}

void intervalChange(int l, int r, int L, int R, int v, int root){
    if (L <= l && r <= R){
        tree[root].add = 0;
        tree[root].max = v;
        tree[root].cover = v;
        return ;
    }
    int mid = (l + r) >> 1;
    pushDown(root);
    if (L <= mid) intervalChange(l, mid, L, R, v, root << 1);
    if (R >= mid + 1) intervalChange(mid + 1, r, L, R, v, root << 1|1);
    pushUp(root);
    return ;
}

void intervalModify(int l, int r, int L, int R, int v, int root){
    if (L <= l && r <= R){
        tree[root].max += v;
        tree[root].add += v;
        return ;
    }
    int mid = (l + r) >> 1;
    pushDown(root);
    if (L <= mid) intervalModify(l , mid, L, R, v, root << 1);
    if (R >= mid + 1) intervalModify(mid + 1, r, L, R, v, root << 1|1);
    pushUp(root);
    return ;
}

ll intervalQuery(int l, int r, int L, int R, int root){
    ll ans = -INF;
    if (L <= l && r <= R) return tree[root].max;
    int mid = (l + r) >> 1;
    pushDown(root);
    if (L <= mid) ans = max(ans, intervalQuery(l, mid, L, R, root << 1));
    if (R >= mid + 1) ans = max(ans, intervalQuery(mid + 1, r, L, R, root << 1|1));
    return ans;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) scanf("%lld", &arr[i]);
    build(1, n, 1);
    for (int i=1; i<=4*MAXN; i++) tree[i].cover = INF;
    while(m--){
        scanf("%d %d %d", &t, &x, &y);
        if (t == 1) {
            scanf("%d", &k);
            intervalChange(1, n, x, y, k, 1);
        }
        else if (t == 2) {
            scanf("%d", &k);
            intervalModify(1, n, x, y, k, 1);
        } else{
            ll ans = intervalQuery(1, n, x, y, 1);
            printf("%lld\n", ans);
        }
    }
    return 0;
}