#include <iostream>
using namespace std;

int x;
int w1[25], w2[25];  // 记录一个同学的两个志愿,只需要满足一个就行了
bool vis[25];  // 这本书是否被拿走了
int total=0;  // 所有可行的结果

void dfs(int n){  // n->当前递归到的层数
    // 递归的结束操作
    if (n == x+1){
        total++;
        return;
    }
    // 继续递归下去
    for(int i=1; i<=x; i++){  // 选择每一本书
        if (vis[i] == 0 && w1[n] == i){  // 志愿1
            vis[i] = 1;
            dfs(n+1);
            vis[i] = 0;  // 回溯,撤销选择
        }
        if (vis[i] == 0 && w2[n] == i){  // 志愿2
            vis[i] = 1;
            dfs(n+1);
            vis[i] = 0;  // 回溯,撤销选择
        }
    }
}

int main(){
    cin >> x;
    if (x == 0){
        cout << 0;
        return 0;
    }
    for (int i=1; i<=x; i++){
        cin >> w1[i] >> w2[i];
    }
    dfs(1);
    cout << total << endl;
    return 0;
}