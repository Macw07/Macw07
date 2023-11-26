#include <iostream>
using namespace std;

int n, m;
int cnt = 0;
int arr[205];
int mem[205][10005];

// 这题原本应该是使用动态规划背包问题解决的，但是wsq想要用递归解决。

int dfs(int index, int sum){
    if (mem[index][sum]) return mem[index][sum];
    if (sum == m){
        cnt++;
        return 0;
    }
    if (sum > m) return 0;
    // 不断进行组合
    for (int i=index; i<=n; i++){
        mem[index][sum] = dfs(i+1, sum+arr[i]);
    }
    return mem[index][sum];
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