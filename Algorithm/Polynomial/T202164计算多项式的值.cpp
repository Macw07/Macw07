#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double ans=1, x, a=1;
    int n;
    cin >> x >> n;
    for (int i=0; i<n; i++){
        a *= x;
        ans += a;
    }
    printf("%.2f", ans);
    return 0;
}