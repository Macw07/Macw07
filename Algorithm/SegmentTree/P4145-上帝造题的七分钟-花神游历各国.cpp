#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 1e5;
struct node{
    long long sum;
    int tag;
    int perfect;
    int count;
};
bool isModified;
int n, m, l, r, opt;
long long arr[MAXN + 5];
node tree[MAXN << 2];

void pushUp(int root){
    if (!tree[root << 1].tag && !tree[root << 1|1].tag){
        tree[root].sum = tree[root << 1].sum + tree[root << 1|1].sum;
    } else tree[root].sum = -1;
    if (tree[root << 1].perfect && tree[root << 1|1].perfect) tree[root].perfect = 1;
    return ;
}

void pushDown(int root){
    if (tree[root].tag){
        tree[root << 1].tag += tree[root].tag;
        tree[root << 1|1].tag += tree[root].tag;
        tree[root].tag = 0;
        tree[root << 1].count = tree[root].count;
        tree[root << 1|1].count = tree[root].count;
    }
    return ;
}

void build(int l, int r, int root){
    if (l == r){
        tree[root].sum = arr[l];
        if (tree[root].sum == 1) tree[root].perfect = 1;
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, root << 1);
    build(mid + 1, r, root << 1|1);
    pushUp(root);
    return ;
}

void change(int l, int r, int L, int R, int root){
    if (tree[root].count >= 6) return ;
    if (L <= l && r <= R){
        tree[root].count += 1;
        tree[root].tag += 1;
        return ;
    }
    pushDown(root);
    int mid = (l + r) >> 1;
    if (L <= mid) change(l, mid, L, R, root << 1);
    if (R > mid) change(mid + 1, r, L, R, root << 1|1);
    pushUp(root);
    return ;
}

long long query(int l, int r, int L, int R, int root){
    long long ans = 0;
    if (l == r) {
        while (tree[root].tag) {
            tree[root].sum = sqrt(tree[root].sum);
            tree[root].tag -= 1;
        }
        if (tree[root].sum == 1) tree[root].perfect = 1;
        return tree[root].sum;
    }
    if (L <= l && r <= R && (tree[root].perfect || tree[root].count > 6)) return (r - l + 1);
    pushUp(root);
    if (L <= l && r <= R && !isModified) return tree[root].sum;
    pushDown(root);
    int mid = (l + r) >> 1;
    if (L <= mid) ans += query(l, mid, L, R, root << 1);
    if (R > mid) ans += query(mid + 1, r, L, R, root << 1|1);
    pushUp(root);
    return ans;
}

int main(){
    // freopen("A.in", "r", stdin);
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%lld", &arr[i]);
    build(1, n, 1);
    scanf("%d", &m);
    while(m--){
        scanf("%d %d %d", &opt, &l, &r);
        if (l > r) swap(l, r);
        if (opt == 0) {
            change(1, n, l, r, 1);
            isModified = 1;
        }
        else {
            long long ans = query(1, n, l, r, 1);
            printf("%lld\n", ans);
        }
    }
    return 0;
}