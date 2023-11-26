#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, mx;
const int maxn = 1e8;
int arr[maxn], vis[maxn], ptr;
queue<int> que;

// 欧拉质数筛
void prime_summon(){
    vis[0] = vis[1] = 1;  // 0&1都不是质数
    for (int i=2; i<=maxn; i++){
        if (!vis[i]) {
            if (i > mx) return ;  // 两个小优化
            arr[ptr++] = i;
        }
        // 质数的倍数都是合数，因此可以直接放弃判断。
        for (int j=0; j<ptr&&arr[j]*i<=maxn; j++){
            vis[arr[j]*i] = 1;
            if (arr[j]*i > mx) break;  // 两个小优化
            if (i % arr[j] == 0) break;  // 说明此时的i已经被筛选过了
        }
    }
    return ;
}

int main(){
    
    while(cin >> n && n != 0) que.push(n), mx = max(mx, n);
    prime_summon();
    while(!que.empty()){
        n = que.front();
        que.pop();
        for (int i=3; i<=n; i++){
            if (i % 2 == 1 && vis[i] == 0 && vis[n-i] == 0){
                printf("%d = %d + %d\n", n, i, n-i);
                break;
            }
        }
    }
    
    return 0;
}