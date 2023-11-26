#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans;
int knowledges[1005];
int interphase[1005];

void dfs(int count, int index){
    if (index > n){
        ans = max(ans, count);
        if (ans == n){
            printf("%d", ans);
            exit(0);
        }
        return;
    }
    // 每个间隔
    for (int i=1; i<=m; i++){
        // 放进去且放得进去
        if (interphase[i]-knowledges[index]>=0){
            interphase[i] -= knowledges[index];
            dfs(count+1, index+1);
            interphase[i] += knowledges[index];
        }
    }
    // 不放这一个元素了
    dfs(count, index+1);  
    return;
}

int main(){
    clock_t begin, end;
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++){
        scanf("%d", &knowledges[i]);
    }
    for (int i=1; i<=m; i++){
        scanf("%d", &interphase[i]);
    }
    // 直接暴力破解
    dfs(0, 1);
    printf("%d\n", ans);
    return 0;
}