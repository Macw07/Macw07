#include <iostream>
using namespace std;

/*
假设有排成一行的N个位置，记为1-N，N一定大于或等于2
开始时机器人在其中的M位置上（M一定是1-N中的一个）
如果机器人来到1位置，那么下一步只能往右来到2位置；
如果机器人来到N位置，那么下一步只能往左来到N-1位置；
如果机器人来到中间位置，那么下一步可以往左走或者往右走；
规定机器人必须走K步，最终能来到P位置(P也是1~N中的一个)的方法有多少种
给定四个参数N、M、K、P，返回方法数。
*/

// TODO 这道题有非常多的解法，分别问：暴力递归、动态规划自顶向下、动态规划动态转移方程。

int N, M, K, P;
int arr[105][105];
int dp[105][105];

// 解法1. 暴力递归解法
// current 代表的是当前的格子，rest代表的是还剩下的步数
int method1(int current, int rest){
    // 递归的结束条件：当步数为0的时候，表示已经不需要再走下去了。
    if (rest == 0){
        if (current == P){
            return 1;
        } else{
            return 0;
        }
    }
    // 分三种情况讨论
    // 1. 当机器人在位置1的时候：只能走到第二个格子上
    if (current == 1){
        return method1(2, rest-1);
    }
    // 2. 当机器人在位置N的时候，只能走到N-1的格子上
    if (current == N){
        return method1(current-1, rest-1);
    }
    // 3. 当机器人在中间的时候，可以向current-1或者current+1两个方向走
    return method1(current-1, rest-1) + method1(current+1, rest-1);
}

// 解法2. 自顶向下法, 通过记忆化搜索来解决
int method2(int current, int rest){
    if (arr[current][rest] != -1){
        return arr[current][rest];
    }
    if (rest == 0){
        if (current == P){
            return 1;
        } else{
            return 0;
        }
    }
    int ans = 0;
    if (current == 1){
        ans = method2(2, rest-1);
    } else if (current == N){
        ans =  method2(current-1, rest-1);
    } else ans = method1(current-1, rest-1) + method1(current+1, rest-1);
    arr[current][rest] = ans;
    return ans;
}

// 解法3. 动态规划状态转移方程（通过列表得出结论）
int method3(){
    dp[P][0] = 1;
    for (int rest=1; rest <= K; rest++){
        dp[1][rest] = dp[2][rest-1];
        for (int j=2; j<N; j++){
            dp[j][rest] = dp[j-1][rest-1]+dp[j+1][rest-1];
        }
        dp[N][rest] = dp[N-2][rest-1];
    }
    return dp[M][K];
}

int main(){
    cin >> N >> M >> K >> P;
    for (int i=1; i<=M; i++){
        for (int j=1; j<=K; j++){
            arr[i][j] = -1;
        }
    }
    cout << method1(M, K) << endl;
    cout << method2(M, K) << endl;
    cout << method3() << endl;
    return 0;
}