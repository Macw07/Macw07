#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int n, m1[30], m2[30], m3[30], mark = 0, ans[30];

void setvalue(int x, int y, int s){
    ans[x] = y;
    m1[y] = s;
    m2[x+y] = s;
    m3[x-y+n] = s;
}

void dfs(int s){  // s代表递归的层数
    if (s > n){
        mark++;
        cout << "sum=" << mark << endl;
        for (int i=1; i<=n; i++) cout << setw(2) << ans[i];
        cout << endl;
        return;
    }
    for (int i=1; i<=n; i++){  // 遍历每一层的棋盘
        // 判断棋盘是否合法
        if (m1[i] || m2[s+i] || m3[s-i+n]) continue;
        setvalue(s, i, 1);  // 设置占用
        dfs(s+1);
        setvalue(s, i, 0);  // 撤销占用 
    }

}

int main(){
    // cin >> n;
    n = 8;
    dfs(1);
    return 0;
}