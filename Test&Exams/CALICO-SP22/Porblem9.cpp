#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
int dp[300] = {0, 1, 1, 6, 11, 47};

int main(){
    /*
    分类讨论：
    1. 一个空位

    2. 两个空位
        直接加一对括号() dp[i-2]
        取反再取反!! dp[i-2]
        或一运算 |1 dp[i-2]
        或零运算 |0 dp[i-2]
        与一运算 &1 dp[i-2]

    3. 三个空位
        或非一 |!1 dp[i-3]
        或非零 |!0 dp[i-3]
        与非零 &!0 dp[i-3]
    */
    for (int i=4; i<=200; i++){

        return ;
    }
    return 0;
}