#include <iostream>
#include <algorithm>
using namespace std;

long long a, b, p;
long long i, j, k;
long long ans = 1;

void quickPower(){
    while (b){
        if (b & 1) {
            ans = ans%p * a%p;
        }  // 如果n的末尾为1
        a = a%p * a%p;
        b >>= 1;
        ans = ans % p;
    }
    return ;
}

int main(){
    cin >> a >> b >> p;
    i=a, j=b, k=p;
    quickPower();
    printf("%lld^%lld mod %lld=%lld\n", i, j, k, ans);
    return 0;
}