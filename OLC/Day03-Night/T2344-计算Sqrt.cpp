#include <algorithm>
#include <iostream>
using namespace std;

int n, arr[105], k;

int main(){
    scanf("%d", &n);
    double l = 1, r = n, ans = 0;
    if (n < 0) {
        cout << -1 << endl;
        return 0;
    }
    while(l <= r){
        double mid = (l+r) / 2;
        if (mid * mid >= n){
            ans = mid;
            r = mid - 0.000001;
        } else l = mid + 0.000001;
    }
    printf("%.5lf", ans);
    return 0;
}
