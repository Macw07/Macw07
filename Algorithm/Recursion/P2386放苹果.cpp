#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ans, m, n;

void dfs(int pos, int current, int startindex){
    // 结束条件 -> n个盘子都用完了
    if (pos == n && !startindex){
        ans++;
        return;
    }
    if (pos == n || pos < 0){
        return;
    }
    for (int i=current; i<=startindex; i++){
        dfs(pos+1, i, startindex-i);
    }
    return;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> m >> n;
        ans = 0;
        dfs(0, 0, m);
        cout << ans << endl;
    }
    return 0;
}