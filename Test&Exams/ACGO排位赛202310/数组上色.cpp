#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 200005;
int n, m;
int l, r, c;
struct node{
    int color;
    int lazy_tag;
} tree[MAXN << 2];

/*
5 3
1 3 5
2 4 6
5 5 7
*/

void pushDown(int root){
    if (tree[root].lazy_tag){
        tree[root << 1].lazy_tag = tree[root].lazy_tag;
        tree[root << 1|1].lazy_tag = tree[root].lazy_tag;

        tree[root << 1].color = tree[root].lazy_tag;
        tree[root << 1|1].color = tree[root].lazy_tag;

        tree[root].lazy_tag = 0;
    }
    return ;
}

void intervalChange(int l, int r, int L, int R, int color, int root){
    // cout << l << " " << r << " " << root << endl;
    if (L <= l && r <= R){
        tree[root].lazy_tag = color;
        tree[root].color = color;
        return ;
    }
    pushDown(root);
    int mid = (l + r) >> 1;
    if (L <= mid) intervalChange(l, mid, L, R, color, root << 1);
    if (R > mid) intervalChange(mid + 1, r, L, R, color, root << 1|1);
    return ;
}

void queryANS(int l, int r, int root){
    if (l == r){
        cout << tree[root].color << " ";
        return ;
    }
    pushDown(root);
    int mid = (l + r) >> 1;
    queryANS(l, mid, root << 1);
    queryANS(mid + 1, r, root << 1|1);
    return ;
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=m; i++){
        scanf("%d %d %d", &l, &r, &c);
        intervalChange(1, n, l, r, c, 1);
    }
    queryANS(1, n, 1);
    return 0;
}