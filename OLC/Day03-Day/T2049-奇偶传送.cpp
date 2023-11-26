#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// 寻找最大的奇数和最大的偶数。
int n, odd, even;

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int t;
        cin >> t;
        if (t % 2) odd = max(odd, t);
        else even = max(even, t);
    }
    printf("answer=%d\n", abs(odd-even));
    printf("%d %d\n", odd, even);
    return 0;
}