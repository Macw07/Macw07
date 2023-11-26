#include <iostream>
#include <algorithm>
using namespace std;

int ans;
int n, b, c;

struct node{
    int left;
    int right;
} tree[1000005];

void dfs(int crt, int depth){
    if (crt == 0) return ;
    ans = max(ans, depth);
    dfs(tree[crt].left, depth+1);
    dfs(tree[crt].right, depth+1);
    return ;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> b >> c;
        tree[i].left = b;
        tree[i].right = c;
    }
    dfs(1, 1);
    cout << ans << endl;
    return 0;   
}