#include <iostream>
using namespace std;

const int MAXN = 1e5 + 5;
typedef long long ll;
int n, m, p;
int t, x, y, k;
ll arr[MAXN];
struct node{
    ll sum;
    ll mul;
    ll add;
} tree[MAXN << 2];

void pushUp(int root){
    tree[root].sum = (tree[root << 1].sum + tree[root << 1|1].sum) % p;
    return ;
}

void pushDown(int root, int llen, int rlen){
    tree[root << 1].sum = (tree[root << 1].sum * tree[root].mul + tree[root].add * llen) % p;
    tree[root << 1|1].sum = (tree[root << 1|1].sum * tree[root].mul + tree[root].add * rlen) % p;

    tree[root << 1].mul = (tree[root].mul * tree[root << 1].mul) % p;
    tree[root << 1|1].mul = (tree[root].mul * tree[root << 1|1].mul) % p;

    tree[root << 1].add = (tree[root << 1].add * tree[root].mul + tree[root].add) % p;
    tree[root << 1|1].add = (tree[root << 1|1].add * tree[root].mul + tree[root].add) % p;

    tree[root].add = 0;
    tree[root].mul = 1;
    return ;
}

void build(int l, int r, int root){
    if (l == r){
        tree[root].sum = arr[l];
        tree[root].mul = 1;
        return ;
    }
    tree[root].mul = 1;
    int mid = (l + r) >> 1;
    build(l, mid, root << 1);
    build(mid + 1, r, root << 1|1);
    pushUp(root);
    return ;
}

void intervalMul(int l, int r, int L, int R, int k, int root){
    if (L <= l && r <= R){
        tree[root].add = (tree[root].add * k) % p;
        tree[root].mul = (tree[root].mul * k) % p;
        tree[root].sum = (tree[root].sum * k) % p;
        return ;
    }
    int mid = (l + r) >> 1;
    int llen = mid - l + 1;
    int rlen = r - mid;
    pushDown(root, llen, rlen);
    if (L <= mid) intervalMul(l, mid, L, R, k, root << 1);
    if (R >= mid + 1) intervalMul(mid + 1, r, L, R, k, root << 1|1);
    pushUp(root);
    return ;
}

void intervalAdd(int l, int r, int L, int R, int k, int root){
    if (L <= l && r <= R){
        int len = (r - l + 1);
        tree[root].sum = (tree[root].sum + (len * k)) % p;
        tree[root].add = (tree[root].add + k) % p;
        return ;
    }
    int mid = (l + r) >> 1;
    int llen = mid - l + 1;
    int rlen = r - mid;
    pushDown(root, llen, rlen);
    if (L <= mid) intervalAdd(l, mid, L, R, k, root << 1);
    if (R >= mid + 1) intervalAdd(mid + 1, r, L, R, k, root << 1|1);
    pushUp(root);
    return ;
}

ll intervalQuery(int l, int r, int L, int R, int root){
    ll ans = 0;
    if (L <= l && r <= R) return tree[root].sum % p;
    int mid = (l + r) >> 1;
    int llen = mid - l + 1;
    int rlen = r - mid;
    pushDown(root, llen, rlen);
    if (L <= mid) ans = (ans + intervalQuery(l, mid, L, R, root << 1)) % p;
    if (R >= mid + 1) ans = (ans + intervalQuery(mid + 1, r, L, R, root << 1|1)) % p;
    return ans;
}

int main(){
    scanf("%d %d %d", &n, &m, &p);
    for (int i=1; i<=n; i++) scanf("%lld", &arr[i]);
    build(1, n, 1);
    while(m--){
        scanf("%d", &t);
        if (t == 1){
            scanf("%d %d %d", &x, &y, &k);
            intervalMul(1, n, x, y, k, 1);
        } else if (t == 2){
            scanf("%d %d %d", &x, &y, &k);
            intervalAdd(1, n, x, y, k, 1);
        } else{
            scanf("%d %d", &x, &y);
            ll ans = intervalQuery(1, n, x, y, 1);
            printf("%lld\n", ans);
        }
    }
    return 0;
}