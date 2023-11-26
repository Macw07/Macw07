#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, ans = 0x7f7f7f7f;
int arr[30], current[30];
int feed[20][30];
int path[30], final_path[30];

void dfs(int depth, int index){
    if (depth > (m+1)) return ;
    if (index > ans) return ;

    if (depth == (m+1)){
        bool flag = true;
        for (int i=1; i<=n; i++){
            if (current[i] < arr[i]) {
                flag = false;
                break;
            }
        }

        if (flag && index < ans) {
            ans = index;
            for (int i=1; i<=ans; i++) final_path[i] = path[i];
        }
    }

    // 选这个饲料，不选这个饲料；
    for (int i=1; i<=n; i++) current[i] += feed[depth][i];
    path[index+1] = depth;
    dfs(depth+1, index + 1);
    for (int i=1; i<=n; i++) current[i] -= feed[depth][i];

    dfs(depth+1, index);
    return ;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    cin >> m;
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            cin >> feed[i][j];
        }
    }
    dfs(1, 0);
    cout << ans << " ";
    for (int i=1; i<=min(25, ans); i++) cout << final_path[i] << " ";
    return 0;
}