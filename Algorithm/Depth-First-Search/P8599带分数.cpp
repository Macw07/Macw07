#include <iostream>
using namespace std;

// 整体算法思路：先求出全排列，然后进行分割。
int n;
int vis[15];
int ans[15];
int total = 0;

// 合并答案
int merge(int l, int r){
    int sum = 0;
    for (int i=l; i<=r; i++){
        sum = sum * 10 + ans[i];
    }
    return sum;
}

// 深度优先DFS
void dfs(int k){  // k代表层数
    // 判断是否是是答案，如果是的话让答案+1
    if (k > 9){
        for (int i=1; i<=7; i++){
            for (int j=i+1; j<=8; j++){
                int a, b, c;
                a = merge(1, i);
                b = merge(i+1, j);
                c = merge(j+1, 9);
                if (n * c == b + a*c){
                    total++;
                }
            }
        }
    }
    
    // 全排列
    for (int i=1; i<=9; i++){
        if (vis[i] == 0){
            vis[i] = 1;
            ans[k] = i;
            dfs(k+1);
            vis[i] = 0;
        }
    }
    return;
}

int main(){
    cin >> n;
    dfs(1);
    cout << total << endl;
    return 0;
}