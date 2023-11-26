#include <iostream>
#include <algorithm>
using namespace std;

// 因为一个数的最后一位只跟前面一个数的最后一位有关因此每次阶乘都取模即可。
long long n, sum = 1;
int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        sum = sum *= i;
        while(sum % 10 == 0){
            sum /= 10;
        }
        sum = sum % 100000000;
    }
    cout << sum%10 << endl;
    return 0;
}