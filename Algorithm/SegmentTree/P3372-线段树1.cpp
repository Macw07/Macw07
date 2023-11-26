#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 5;

int n, m, t;
int x, y, k;
struct node{
    ll sum;
    ll lazy_tag;
};
node tree[MAXN << 2];
ll arr[MAXN];

void pushUp(int root){
    tree[root].sum = tree[root << 1].sum + tree[root << 1|1].sum;
    return ;
}

void pushDown(int root, int llen, int rlen){
    if (tree[root].lazy_tag){
        tree[root << 1].lazy_tag += tree[root].lazy_tag;
        tree[root << 1|1].lazy_tag += tree[root].lazy_tag;
        tree[root << 1].sum += llen * tree[root].lazy_tag;
        tree[root << 1|1].sum += rlen * tree[root].lazy_tag;
        tree[root].lazy_tag = 0;
    }
    return ;
}

void build_tree(int l, int r, int root){
    if (l == r){
        tree[root] = (node){arr[l], 0};
        return ;
    }
    int mid = (l + r) >> 1;
    build_tree(l, mid, root << 1);
    build_tree(mid+1, r, root << 1|1);
    pushUp(root);
    return ;
}

void singleUpdate(int l, int r, int k, int v, int root){
    if (l == r){
        tree[l].sum += v;
        return ;
    }
    int mid = (l + r) >> 1;
    if (k <= mid) singleUpdate(l, mid, k, v, root << 1);
    else singleUpdate(mid + 1, r, k, v, root << 1|1);
    pushUp(root);
    return ;
}

void intervalUpdate(int l, int r, int L, int R, int v, int root){
    if (L <= l && r <= R){
        tree[root].lazy_tag += v;
        tree[root].sum += (r - l + 1) * v;
        return ;
    }
    int mid = (l + r) >> 1;
    int llen = mid - l + 1;
    int rlen = r - mid;
    pushDown(root, llen, rlen);
    if (L <= mid) intervalUpdate(l, mid, L, R, v, root << 1);
    if (R > mid) intervalUpdate(mid+1, r, L, R, v, root << 1|1);
    pushUp(root);
    return ;
}

ll intervalQuery(int l, int r, int L, int R, int root){
    ll sum = 0;
    if (L <= l && r <= R) return tree[root].sum;
    int mid = (l + r) >> 1;
    int llen = mid - l + 1;
    int rlen = r - mid;
    pushDown(root, llen, rlen);
    if (L <= mid) sum += intervalQuery(l, mid, L, R, root << 1);
    if (R > mid) sum += intervalQuery(mid + 1, r, L, R, root << 1|1);
    return sum;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) scanf("%lld", &arr[i]);
    build_tree(1, n, 1);
    while(m--){
        scanf("%d", &t);
        if (t == 1){
            scanf("%d %d %d", &x, &y, &k);
            intervalUpdate(1, n, x, y, k, 1);
        } else{
            scanf("%d %d", &x, &y);
            ll ans = intervalQuery(1, n, x, y, 1);
            printf("%lld\n", ans);
        }
    }
    return 0;
}