#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

// 这道题是真的不懂，救命，看来我对递归的概念真的很欠缺啊。

int n;
char arr[1050][2050];

void dfs(int x, int y, int deep){
    if (deep == 1){  // 最小单位
        arr[x][y] = '/';
        arr[x][y+1] = '\\';
        arr[x+1][y-1] = '/';
        arr[x+1][y] = '_';
        arr[x+1][y+1] = '_';
        arr[x+1][y+2] = '\\';
        return ;
    }
    // 三个
    dfs(x, y, deep-1);
    dfs(x + pow(2, deep-1), y - pow(2, deep-1), deep-1);
    dfs(x + pow(2, deep-1), y + pow(2, deep-1), deep-1);
    return ;
}

int main(){
    cin >> n;
    memset(arr, ' ', sizeof arr);
    dfs(1, pow(2, n), n);
    for (int i=1; i<=pow(2, n); i++){
        for (int j=1; j<=pow(2, n+1); j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}