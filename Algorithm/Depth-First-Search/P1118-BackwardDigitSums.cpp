#include <iostream>
#include <algorithm>
using namespace std;

// 真服了，做的时候把n写成常量4，导致一直过不去。

int n, sum;
int vis[15];
int ans[15];
int triangle[30][30];

void next_permutation(int index, int sum_t){
    if (sum_t > sum) return ;
    if (index > n){
        if (sum == sum_t){
            for (int i=1; i<=n; i++) cout << ans[i] << ' ';
            exit(0);
        }
        return ;
    }
    for (int i=1; i<=n; i++){
        if (vis[i]) continue;
        vis[i] = 1;
        ans[index] = i;
        next_permutation(index+1, sum_t + i*triangle[n][index]);
        vis[i] = 0;
    }
    return ;
}

int main(){
    cin >> n >> sum;
    // 构建出一个杨辉三角（看题解）
    triangle[1][1] = 1;
    for (int i=2; i<=n; i++){
        for (int j=1; j<=i; j++){
            triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
        }
    }
    next_permutation(1, 0);
    return 0;
}