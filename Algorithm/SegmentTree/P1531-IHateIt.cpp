#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 5;
char c;
int n, m, a, b;
int arr[MAXN];
int tree[MAXN << 2];

void pushUp(int root){
    tree[root] = max(tree[root << 1], tree[root << 1|1]);
    return ;
}

void build(int l, int r, int root){
    if (l == r){
        tree[root] = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, root << 1);
    build(mid + 1, r, root << 1|1);
    pushUp(root);
    return ;
}

void singleUpdate(int l, int r, int k, int v, int root){
    if (l == k && r == k){
        if (tree[root] < v) tree[root] = v;
        return ;
    }
    int mid = (l + r) >> 1;
    if (k <= mid) singleUpdate(l, mid, k, v, root << 1);
    else singleUpdate(mid + 1, r, k, v, root << 1|1);
    pushUp(root);
    return ;
}

int query(int l, int r, int L, int R, int root){
    int ans = -0x7f7f7f7f;
    if (L <= l && r <= R) return tree[root];
    int mid = (l + r) >> 1;
    if (L <= mid) ans = max(ans, query(l, mid, L, R, root << 1));
    if (R > mid) ans = max(ans, query(mid+1, r, L, R, root << 1|1));
    return ans;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) scanf("%d", &arr[i]);
    
    // to build a segement tree;
    build(1, n, 1);
    
    while(m--){
        cin >> c >> a >> b;
        if (c == 'U') singleUpdate(1, n, a, b, 1);
        else{
            int ans = query(1, n, a, b, 1);
            printf("%d\n", ans);
        }
    }
    return 0;
}