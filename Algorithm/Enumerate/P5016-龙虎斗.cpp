#include <iostream>
#include <cmath>
using namespace std;

long long n, m, p1, s1, s2, p2;
long long dragon, tiger;
long long arr[100005];
long long difference = 0x7f7f7f7f7f7f;

// 问题一：题目没看清。
// 问题二：开了long long但没完全开。

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    cin >> m >> p1 >> s1 >> s2;
    arr[p1] += s1;
    for (int i=1; i<m; i++) dragon += arr[i] * (m-i);
    for (int j=m+1; j<=n; j++) tiger += arr[j] * (j-m);

    difference = abs(dragon - tiger);
    p2 = m;

    for (int i=1; i<=n; i++){
        // 将你手里的s2位工兵全部派往p2兵营。
        if (i<m){
            unsigned long long t = abs((dragon + s2 * (m-i)) - tiger);
            if (t < difference){
                difference = t;
                p2 = i;
            }
        } else if (i > m){
            unsigned long long t = abs((tiger + s2 * (i-m)) - dragon);
            if (t < difference){
                difference = t;
                p2 = i;
            }
        }
    }
    cout << p2 << endl;
    return 0;
}