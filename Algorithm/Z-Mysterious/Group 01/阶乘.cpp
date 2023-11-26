// 阶乘
#include <iostream>
using namespace std;

long power(long n);

int main(){
    long n;
    cin >> n;
    long r = power(n);
    cout << r;
}

long power(long n){
    int product = 1;
    for (int i=1; i<=n; i++){
        product *= i;
    }
    return product;
}