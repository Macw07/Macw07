#include <iostream>
using namespace std;

long long t;
long long n;
long long MOD = 3359232;
// 3359232

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        n /= 3;
        // 长度为n的二进制。
        long long tmp = 1;
        n += 1;
        for (int i=1; i<=n; i++){
            tmp = (tmp * 2) % MOD;
        }
        tmp -= 2;
        cout << tmp << endl;
    }
    return 0;
}