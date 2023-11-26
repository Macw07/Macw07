#include <iostream>
using namespace std;

const int MAXN = 2e5 + 5;
int n, m, t, x, y;
struct node{
    int count;
    int tag;
} tree[MAXN << 2];
string str;
int arr[MAXN];

void pushUp(int root){
    tree[root].count = tree[root << 1].count + tree[root << 1|1].count;
    return ;
}

void pushDown(int root, int llen, int rlen){
    if (tree[root].tag){
        tree[root << 1].count = llen - tree[root << 1].count;
        tree[root << 1|1].count = rlen - tree[root << 1|1].count;
        tree[root << 1].tag ^= 1;
        tree[root << 1|1].tag ^= 1;
        tree[root].tag = 0;
    }
    return ;
}

void build(int l, int r, int root){
    if (l == r){
        tree[root].count = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, root << 1);
    build(mid + 1, r, root << 1|1);
    pushUp(root);
    return ;
}

void updateInterval(int l, int r, int L, int R, int root){
    if (L <= l && r <= R){
        tree[root].tag ^= 1;
        tree[root].count = (r - l + 1) - tree[root].count;
        return ;
    }
    int mid = (l + r) >> 1;
    int llen = mid - l + 1;
    int rlen = r - mid;
    pushDown(root, llen, rlen);
    if (L <= mid) updateInterval(l, mid, L, R, root << 1);
    if (R >= mid + 1) updateInterval(mid + 1, r, L, R, root << 1|1);
    pushUp(root);
    return ;
}

int queryInterval(int l, int r, int L, int R, int root){
    int ans = 0;
    if (L <= l && r <= R)  return tree[root].count;
    int mid = (l + r) >> 1;
    int llen = mid - l + 1;
    int rlen = r - mid;
    pushDown(root, llen, rlen);
    if (L <= mid) ans += queryInterval(l, mid, L, R, root << 1);
    if (R >= mid + 1) ans += queryInterval(mid + 1, r, L, R, root << 1|1);
    return ans;
}

int main(){
    scanf("%d %d", &n, &m);
    cin >> str;
    for (int i=1; i<=n; i++) arr[i] = str[i-1] - '0';
    build(1, n, 1);
    while(m--){
        scanf("%d %d %d", &t, &x, &y);
        if (t == 0){
            updateInterval(1, n, x, y, 1);
        } else{
            int ans = queryInterval(1, n, x, y, 1);
            printf("%d\n", ans);
        }
    }
    return 0;
}