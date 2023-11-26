#include <iostream>
#include <cstring>
using namespace std;

int n, k, p, t;
int color[200005], price;
int num[55], ans;  // 表示第i个颜色在之前出现了几次。

int main(){
    scanf("%d %d %d", &n, &k , &p);
    for (int i=1; i<=n; i++) {
        scanf("%d %d", &color[i], &price);
        if (price <= p){
            for (int j=i; j>t; j--){
                num[color[j]] += 1;
            }
            t = i, ans += num[color[i]]-1;
        } else{
            ans += num[color[i]];
        }
    }
    cout << ans << endl;
    return 0;
}
