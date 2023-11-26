// ? WSQ同学还是很欣慰的,毕竟自己可以写出一个大概的思路. 但是对DFS的决策问题的理解还是非常的浅显,无法靠自己一个人搞定这些题. 或许这个就是这个等级题目的魅力所在了吧.
// ? 于此同时,我还深刻的意识到了我对DFS的欠缺,希望这几天努力学学,弯道超车. 这几天主要目标就是攻破DFS和BFS,最好可以把DP问题解决了.
// ? 集训之前,能做努力所少努力多少.

#include <iostream>
#include <cstring>
using namespace std;

int t, w;
int arr[1050];
int memo[1050][3][35];   // 三维数组f表状态

int dfs(int i, int j, int k){  // i为时间点, j为哪棵树, k为移动了多少次
    if (i > t) return 0;  // 边界条件
    if (memo[i][j][k] != -1) return memo[i][j][k];  //如果搜过了就直接返回

    int tmp1=0, tmp2=0;
    if (k < w && arr[i] != j){  // 如果在这个时间点里,当前位置会有果子落下,就不走
        tmp1 = dfs(i+1, -1*j+3, k+1) + 1;
    }
    tmp2 = dfs(i+1, j, k) + (j == arr[i] ? 1 : 0);  // 是否有果子落下来 
    
    return memo[i][j][k] = max(tmp1, tmp2);  // 返回接到果子多的决策
}
int main(){
    cin >> t >> w;
    for (int i=1; i<=t; i++){
        cin >> arr[i];
    }
    memset(memo, -1, sizeof(memo));
    cout << dfs(1, 1, 0) << endl;
    return 0;
}