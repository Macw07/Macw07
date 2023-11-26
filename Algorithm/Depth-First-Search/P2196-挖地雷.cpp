#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, ans;
int arr[25][25];
int vis[25], cnt[25];
int temp[25], ans_p[25]; 

void dfs(int vertex, int weight, int steps){
    bool flag = true;
    for(int i=vertex + 1; i<=n; i++){
        if (vis[i]) continue;
        if (arr[vertex][i]){
            vis[i] = 1;
            flag = false;
            temp[steps] = vertex;
            dfs(i, weight + cnt[i], steps + 1);
            vis[i] = 0;
        }
    }
    if (flag && weight > ans){
        memset(ans_p, 0, sizeof ans_p);
        ans = weight;
        for (int i=0; i<steps; i++){
            ans_p[i] = temp[i];
        }
        ans_p[steps] = vertex;
    }
    return ;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> cnt[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=i+1; j<=n; j++){
            int t; cin >> t;
            arr[i][j] = t;
        }
    }
    for (int i=1; i<=n; i++){
        memset(vis, 0, sizeof vis);
        temp[0] = i;
        dfs(i, cnt[i], 1);
    }
    for (int i=1; i<=n; i++){
        if (ans_p[i]) cout << ans_p[i] << " ";
        else break;
    }
    cout << endl << ans << endl;
    return 0;
}