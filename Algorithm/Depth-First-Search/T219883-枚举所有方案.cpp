#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[55] = {1};
int vis[55];

void dfs(int index, int target){
    if (index == target+1){
        for (int i=1; i<index; i++) cout << arr[i] << ' ';
        cout << endl;
        return ;
    }

    for (int i=n; i>=1; i--){
        if (vis[i] || arr[index-1] > i) continue;
        vis[i] = 1;
        arr[index] = i;
        dfs(index+1, target);
        vis[i] = 0;
    }
    return ;
}

int main(){
    cin >> n;
    cout << endl;
    // 选一个，选两个，一直选到n个为止。
    for (int i=1; i<=n; i++) dfs(1, i);
    return 0;
}