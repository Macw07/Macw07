#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// 一直在思考，自己dfs为什么老写不好，虽然比之前长进很多，但还是差了点。
// dfs bfs得多练习，这种东西练多了自然就会了，虽然过程很艰辛。

int n, ans = 0x7f7f7f7f;
int s[20], b[20];

void dfs(int index, int cs, int cb){
    if (index > n){  // 当index大于n的时候，代表所有状态已经设置完成了，可以进行结果的判断和存储
        if (cs == 1 && cb == 0) return;  // 排除是清水的可能性
        ans = min(ans, abs(cs-cb));
        return;
    }
    // 进行两个选择：选和不选
    dfs(index+1, cs*s[index], cb+b[index]);  // 这里要注意，一个是累加，一个是累乘
    dfs(index+1, cs, cb);
    return ;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        scanf("%d %d", &s[i], &b[i]);  // 虽然但是，scanf的速度确实比cin要快得多
    }
    dfs(1, 1, 0);
    printf("%d", ans);
    return 0;   
}