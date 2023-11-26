#include <iostream>
#include <algorithm>
using namespace std;

int n, q, m;
int l, r, t;
int arr[100005];

int main(){
    scanf("%d %d", &n, &q);
    for (int i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
        m = max(arr[i], m);
    }
    sort(arr+1, arr+1+n);
    while(q--){
        scanf("%d %d", &l, &r);
        int lb = lower_bound(arr+1, arr+1+n, l) - arr;
        int ub = upper_bound(arr+1, arr+1+n, r) - arr;
        printf("%d\n", ub - lb);
    }
    return 0;
}