#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 5e4 + 5;
int n, m, x, y;
struct node{
    int value;
    string str;
};
node arr[MAXN];
string str[MAXN];
int num[MAXN];
int tree[MAXN << 2];

bool cmp(node a, node b){
    int len = min(a.str.size(), b.str.size());
    for (int i=0; i<len; i++){
        if (tolower(a.str[i]) != tolower(b.str[i])){
            return tolower(a.str[i]) < tolower(b.str[i]);
            
        }
    }
    return a.str.size() < b.str.size();
}

void pushUp(int root){
    tree[root] = max(tree[root << 1], tree[root << 1|1]);
    return ;
}

void build(int l, int r, int root){
    if (l == r) {
        tree[root] = num[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, root << 1);
    build(mid + 1, r, root << 1|1);
    pushUp(root);
    return ;
}

int queryInterval(int l, int r, int L, int R, int root){
    int ans = 0;
    if (L <= l && r <= R) {
        return tree[root];
    }
    int mid = (l + r) >> 1;
    if (L <= mid) ans = max(ans, queryInterval(l, mid, L, R, root << 1));
    if (R >= mid + 1) ans = max(ans, queryInterval(mid + 1, r, L, R, root << 1|1));
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
       cin >> str[i];
       arr[i].str = str[i];
       arr[i].value = i;
    }
    sort(arr+1, arr+1+n, cmp);
    for (int i=1; i<=n; i++)  num[arr[i].value] = i;

    build(1, n, 1);
    while(m--){
        cin >> x >> y;
        string ans = arr[queryInterval(1, n, x, y, 1)].str;
        cout << ans << endl;
    }
    return 0;
}