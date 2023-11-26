#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, ctrl = 0;
    double ans;
    cin >> n;
    for (int i=1; i<=n; i++){
        if (ctrl == 0) ans += 1.00 / i;
        else ans -= 1.00 / i;
        ctrl ^= 1;
    }
    printf("%.3lf\n", ans);
    return 0;
}