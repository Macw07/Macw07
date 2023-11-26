#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e6 + 5;
int n, m, c;
bool flag = true;
int arr[MAXN];
struct node{
    int max;
    int min;
} tree[MAXN << 2];

void pushUp(int root){
    tree[root].min = min(tree[root << 1].min, tree[root << 1|1].min);
    tree[root].max = max(tree[root << 1].max, tree[root << 1|1].max);
    return ;
}

void build(int l, int r, int root){
    tree[root].min = 0x7f7f7f7f;
    if (l == r){
        tree[root].max = arr[l];
        tree[root].min = arr[r];
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, root << 1);
    build(mid + 1, r, root << 1|1);
    pushUp(root);
    return ;
}

int queryMax(int l, int r, int L, int R, int root){
    int ans = -0x7f7f7f7f;
    if (L <= l && r <= R) return tree[root].max;
    int mid = (l + r) >> 1;
    if (L <= mid) ans = max(ans, queryMax(l, mid, L, R, root << 1));
    if (R >= mid + 1) ans = max(ans, queryMax(mid + 1, r, L, R, root << 1|1));
    return ans;
}

int queryMin(int l, int r, int L, int R, int root){
    int ans = 0x7f7f7f7f;
    if (L <= l && r <= R) return tree[root].min;
    int mid = (l + r) >> 1;
    if (L <= mid) ans = min(ans, queryMin(l, mid, L, R, root << 1));
    if (R >= mid + 1) ans = min(ans, queryMin(mid + 1, r, L, R, root << 1|1));
    return ans;
}

int main(){
    scanf("%d %d %d", &n, &m, &c);
    for (int i=1; i<=n; i++) scanf("%d", &arr[i]);
    build(1, n, 1);
    for (int i=1; i+m-1<=n; i++){
        int ans1 = queryMax(1, n, i, i+m-1, 1);
        int ans2 = queryMin(1, n, i, i+m-1, 1);
        if (ans1 - ans2 <= c) {
            cout << i << endl;
            flag = false;
        }
    }
    if (flag) cout << "NONE" << endl;
    return 0;
}