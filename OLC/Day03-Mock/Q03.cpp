#include <iostream>
#include <algorithm>
using namespace std;

int n, m, total;
int a[20005], b[20005];

int main(){
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) scanf("%d", &a[i]);
    for (int i=1; i<=m; i++) scanf("%d", &b[i]);
    sort(a+1, a+1+n);
    sort(b+1, b+1+m);
    int l = 1, r = 1;
    while(l <= n && r <= m){
        if (b[r] >= a[l]){
            total += b[r];
            r++; l++;
        } else r++;
    }
    if (l <= n) cout << "you died!" << endl;
    else cout << total << endl;
    return 0;
}