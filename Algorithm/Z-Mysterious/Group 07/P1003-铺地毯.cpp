#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = -1;
int tx, ty;
const int maxn = 10000 + 5;
int a[maxn], b[maxn], c[maxn], d[maxn];

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }
    scanf("%d %d", &tx, &ty);
    for (int i=1; i<=n; i++){
        if (tx >= a[i] && tx <= a[i] + c[i] && ty >= b[i] && ty <= b[i] + d[i]){
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}