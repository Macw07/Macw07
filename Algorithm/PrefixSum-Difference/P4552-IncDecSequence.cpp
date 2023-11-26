#include <iostream>
#include <cmath>
using namespace std;

long long n, ans;
long long pos, neg;
long long arr[100005];
long long diff[100005];

int main(){
    scanf("%lld", &n);
    for (int i=1; i<=n; i++){
        scanf("%lld", &arr[i]);
        diff[i] = arr[i] - arr[i-1];
    }
    for (int i=2; i<=n; i++){
        if (diff[i] > 0) pos += diff[i];
        else neg -= diff[i];  // 让负数以正数形式存储。
    }
    cout << max(pos, neg) << endl;
    cout << abs(pos-neg) + 1 << endl;
    return 0;
}