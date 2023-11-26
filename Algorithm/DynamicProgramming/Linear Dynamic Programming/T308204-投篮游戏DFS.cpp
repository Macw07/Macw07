#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;  // n 个数
int arr[1005];
int memo[1005];
int ans = -0x7f7f7f7f;  // 最终答案

// index 代表我选到了第几个数
// sum 代表我选到第index个数以后的最长长度
int dfs(int index){
    if (memo[index]) return memo[index];

    // cout << 1 << endl;
    for (int i=index+1; i<=n; i++){
        if (arr[index] > arr[i]){ // 代表可以选这个数
            memo[index] = max(memo[index], dfs(i) + 1);
        }
    }
    
    return memo[index];
}

int main(){
    cin >> n;
    arr[0] = 0x7f7f7f7f;
    // memset(memo, -1, sizeof memo);
    // memo[1] = 1;
    for (int i=1; i<=n; i++) cin >> arr[i];
    cout << dfs(0) << endl;
    return 0;
}