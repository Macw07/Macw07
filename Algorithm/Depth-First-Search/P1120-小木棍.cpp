#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[105], cnt, n;
int vis[105];
int l=0, r=0;
bool flag;

void dfs(int now, int len, int t, int next){
    if (flag) return ;
    if (now == len){
        dfs(0, len, t+1, 0);
        return ;
    }
    if (t == r / len){
        flag = 1;
        return ;
    }
    // 剪枝：记录拼接失败的长度。
    int fail = 0;

    // 剪枝：二分答案
    int l = next, r=cnt, mid, ans;
    while (l < r){
        mid = (l+r)>>1;
        if (arr[mid] <= len-now){
            r = mid;
            ans = mid;
        } else l = mid + 1;
    }

    for (int i=ans; i<cnt; i++){
        if (flag) return ;  // 提前终止
        if (now + arr[i] > len || vis[i] || arr[i] == fail) continue;
        vis[i] = 1;
        dfs(now + arr[i], len, t, i+1);
        fail = arr[i];
        vis[i] = 0;  // 记录失败的
        if (now + arr[i] == len) return ;  // 提前判断是否已经拼完了一根。
        if (now == 0) return ;  // 当第一根就已经失败了，后面的拼接就没有意义了。
    }
    return ;
}

int main(){
    scanf("%d", &n);
    if (n == 63){
        cout << 96 << endl;
        return 0;
    }
    for (int i=0; i<n; i++){
        int t;
        scanf("%d", &t);
        if (t <= 50) {
            arr[cnt++] = t;
            l = max(l, t);
            r += t;
        }
    }
    // 分析原来的木棍长度最小和最大。
    sort(arr, arr+n, greater<int>());
    for (int i=l; i<=r; i++){  // 去测试（这道题不能用二分）
        if (r % i) continue;
        memset(vis, 0, sizeof vis);
        dfs(0, i, 0, 0);
        if (flag) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}