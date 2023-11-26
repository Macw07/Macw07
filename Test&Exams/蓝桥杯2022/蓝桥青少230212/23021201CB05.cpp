#include <iostream>
#include <algorithm>
using namespace std;

int ans=0x7f7f7f7f;
int m, n, k;;
int ai[1005], bi[1005], ci[1005];

void dfs(int index, int a, int b, int c){
    // 如果达到了最低要求，返回结果
    if (index > k) return;
    if (a >= m && b >= n){
        ans = min(ans, c);
        return;
    }
    // 两种决策，拿和不拿
    dfs(index+1, a+ai[index], b+bi[index], c+ci[index]);
    dfs(index+1, a, b, c);
    return;
}

int main(){
    scanf("%d %d", &m, &n);
    scanf("%d", &k);
    for (int i=1; i<=k; i++){
        scanf("%d %d %d", &ai[i], &bi[i], &ci[i]);
    }
    dfs(1, 0, 0, 0);
    cout << ans << endl;
    return 0;
}