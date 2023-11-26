#include <iostream>
using namespace std;

int n, m;

// 这题想了很久，没写出来，研究了一下题解。

int dfs(int n, int m){
    if (n == 1 || m == 1) return 1;  // Base Case: 如果要划分的数为1的话，就直接返回1
    if (n < m) return dfs(n, n);  // n<m : m大于n，n是不可能被大于自己的数划分的，所以这个条件相当于(n,n)，n被小于等于自己的数划分
    if (n == m) return 1 + dfs(n, n-1);  // 减1并进行递归，可能次数+1
    return dfs(n-m, m)+dfs(n, m-1);  // n被小于m的数划分
}

int main(){
    cin >> n;
    if (n == 1) {cout << 1; return 0;}  // 如果n是1的话，只能被划分成1
    cout << dfs(n, n) << endl;
    return 0;
}