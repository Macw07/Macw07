#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

char arr[105][105];
int ans, n, m, target;

// 这道题虽然是一个暴力的题目，但是如果纯暴力做的话O(n^4)会直接TLE，发生超级大的问题
// 因此需要使用dfs来实现比较方便。

void right(int i, int j, int r){
    if (r == target){
        ans ++;
        return ;
    }
    if (arr[i][j+1] == '.') right(i, j+1, r+1);
    return ;
}

void under(int i, int j, int r){
    if (r == target){
        ans ++;
        return ;
    }
    if (arr[i+1][j] == '.') under(i+1, j, r+1);
    return ;
}

int main(){
    cin >> n >> m >> target;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (arr[i][j] == '.'){
                right(i, j, 1);
                under(i, j, 1);
            }
        }
    }
    if (target == 1) ans /= 2;  // 特殊判断
    cout << ans << endl;
    return 0;
}