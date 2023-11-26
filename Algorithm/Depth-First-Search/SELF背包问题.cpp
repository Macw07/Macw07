#include <iostream>
#include <cmath>
using namespace std;

int n, m;
int w[100], v[100];

// 解法1. 暴力尝试
// index 表示当前尝试到的状态， bag 表示剩余背包的容量
int process1(int index, int bag){
    if (index == n) return 0;  // 如果尝试完了，就不尝试了
    if (bag < 0) return -1;  // 不合法的背包容量
    // 进行尝试，01背包的尝试为：拿和不拿，因此进行两个判断即可
    // 不拿的价值递归
    int p1 = process1(index+1, bag);
    // 拿的价值递归
    int next = process1(index+1, bag-w[index]);
    int p2 = 0;
    if (next != -1){
        p2 = v[index] + next;
    }
    return max(p1, p2);
}

int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> w[i];
    }
    for (int i=0; i<n; i++){
        cin >> v[i];
    }
    cout << process1(0, m) << endl;
}

/*
7 15
3 2 4 7 3 1 7
5 6 3 19 12 4 2
*/