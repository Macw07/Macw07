#include <iostream>
#include <algorithm>
using namespace std;

// 在极端情况下，贪心不适用，N<=18，因此考虑暴力搜索。

int n, w, ans = 0x7f7f7f7f;
int arr[20];
int vis[20];  // vis[i]表示第i个人是否已经上车。

// depth表示已经处理好了depth-1个同学。
// steps表示一共需要多少辆缆车，即答案。
// current表示当前缆车已经乘坐的重量。
void dfs(int depth, int steps, int current){
    if (steps >= ans) return ;
    if (depth > n){
        // cout << steps << endl;
        ans = min(ans, steps);
        return ;
    }
    for (int i=1; i<=n; i++){
        if (vis[i]) continue;
        vis[i] = 1;
        if (current + arr[i] <= w){
            dfs(depth + 1, steps, current + arr[i]);
        } else dfs(depth + 1, steps + 1, arr[i]);
        vis[i] = 0;
    }
    return ;
}

int main(){
    cin >> n >> w;
    for (int i=1; i<=n; i++) cin >> arr[i];
    sort(arr+1, arr+1+n, greater<int>());
    dfs(1, 1, 0);
    cout << ans << endl;
    return 0;
}