#include <iostream>
#include <algorithm>
using namespace std;

int n, win, ans;
int ptr1 = 1, ptr2 = 1;
int a[105], b[105];

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &a[i]);
    for (int i=1; i<=n; i++) scanf("%d", &b[i]);
    sort(a+1, a+1+n); sort(b+1, b+1+n);
    while(ptr1 <= n && ptr2 <= n){
        if (a[ptr1] > b[ptr2]){
            ptr1++;
            ptr2++;
            win += 1;
        } else ptr1++;
    }
    // ans = 200 * win - 200*(n-win);
    ans = 200*(2 * win - n);
    cout << ans << endl;
    return 0;
}