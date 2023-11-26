#include <iostream>
#include <algorithm>
using namespace std;

int n, m, cost = 0x7f7f7f7f;
int arr[15];

void dfs(int depth, int area, int cost_per){
    if (area == m && depth == n + 1){
        cost = min(cost_per, cost);  // 保存答案。
        return ;
    }
    if (area > m) return ; 
    if (cost_per > cost) return ; 
    if (depth > n) return ; 

    // 尝试用第arr[depth]个砖头换所有的砖头。
    for (int i=0; i*i<=m-area; i++){
        int cost_ = (arr[depth]-i)*(arr[depth]-i);
        if (cost_ > cost) continue;
        dfs(depth+1, area + i * i , cost_per + cost_);
    }
    return ;
}

bool cmp(int a, int b) {return a > b;}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++) scanf("%d", &arr[i]);
    arr[n+1] = 100005;
    sort(arr+1, arr+1+n, cmp);
    dfs(1, 0, 0);
    if (cost == 0x7f7f7f7f) cout << -1 << endl;
    else cout << cost << endl;
    return 0;
}