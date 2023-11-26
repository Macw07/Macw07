#include <iostream>
using namespace std;

int n, m;
int cnt = 0;
int arr[205];

// 这题原本应该是使用动态规划背包问题解决的，但是wsq想要用递归解决。

void dfs(int index, int sum){
    if (sum == m){
        cnt++;
        return;
    }
    if (sum > m) return;
    // 不断进行组合
    for (int i=index; i<=n; i++){
        dfs(i+1, sum+arr[i]);
    }
    return;
}


int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
    dfs(1, 0);
    cout << cnt << endl;
    return 0;
}