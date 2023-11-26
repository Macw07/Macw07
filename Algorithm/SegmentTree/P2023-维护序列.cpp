#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 5;
ll arr[MAXN];
int n, m ,p;
int op, t, g, c;
struct node{
    ll add;
    ll mul;
    ll sum;
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

    tree[root << 1].add = (tree[root].mul * tree[root << 1].add + tree[root].add) % p;
    tree[root << 1|1].add = (tree[root].mul * tree[root << 1|1].add + tree[root].add) % p;

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

void intervalmul(int l, int r, int L, int R, int k, int root){
    if (L <= l && r <= R){
        tree[root].sum = (tree[root].sum * k) % p;
        tree[root].mul = (tree[root].mul * k) % p;
        tree[root].add = (tree[root].add * k) % p;
        return ;
    }
    int mid = (l + r) >> 1;
    int llen = mid - l + 1;
    int rlen = r - mid;
    pushDown(root, llen, rlen);
    if (L <= mid) intervalmul(l , mid, L, R, k, root << 1);
    if (R >= mid + 1) intervalmul(mid + 1, r, L, R, k, root << 1|1);
    pushUp(root);
    return ;
}

void intervalAddition(int l, int r, int L, int R, int k, int root){
    if (L <= l && r <= R){
        int len = r - l + 1;
        tree[root].sum = (tree[root].sum + (len * k)) % p;
        tree[root].add = (tree[root].add + k) % p;
        return ;
    }
    int mid = (l + r) >> 1;
    int llen = mid - l + 1;
    int rlen = r - mid;
    pushDown(root, llen, rlen);
    if (L <= mid) intervalAddition(l, mid, L, R, k, root << 1);
    if (R >= mid + 1) intervalAddition(mid + 1, r, L, R, k, root << 1|1);
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
    if (L <= mid) ans = (ans + intervalQuery(l , mid, L, R, root << 1)) % p;
    if (R >= mid + 1) ans = (ans + intervalQuery(mid + 1, r, L, R, root << 1|1)) % p;
    return ans;
}

int main(){
    scanf("%d %d", &n, &p);
    for (int i=1; i<=n; i++) scanf("%lld", &arr[i]);
    scanf("%d", &m);
    build(1, n, 1);
    while(m--){
        scanf("%d", &op);
        if (op == 1){
            scanf("%d %d %d", &t, &g, &c);
            intervalmul(1, n, t, g, c, 1);
        } else if (op == 2){
            scanf("%d %d %d", &t, &g, &c);
            intervalAddition(1, n, t, g, c, 1);
        } else{
            scanf("%d %d", &t, &g);
            ll ans = intervalQuery(1, n, t, g, 1);
            ans %= p;
            printf("%lld\n", ans);
        }
    }
    return 0;
}