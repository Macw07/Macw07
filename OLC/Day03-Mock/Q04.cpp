#include <iostream>
#include <algorithm>
using namespace std;

int n, k, m, total, ans = 0x7f7f7f7f;
int prefix_sum[100000];

int main(){
    scanf("%d %d %d", &n, &k, &m);
    for (int i=1; i<=m; i++){
        int t;
        scanf("%d", &t);
        prefix_sum[t] += 1;
    }
    for (int i=1; i<=n; i++) prefix_sum[i] += prefix_sum[i-1];
    for (int i=1; i<=n-k; i++){
        int tmp = prefix_sum[i+k-1] - prefix_sum[i-1];
        ans = min(tmp, ans);
    }
    cout << ans << endl;
    return 0;
}