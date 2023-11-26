#include <iostream>
#include <algorithm>
using namespace std;

long long fib(int n){
    // 求出斐波那契数列第n项的结果
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n-1)+fib(n-2);
}

int main(){
    cout << fib(6) << endl;
    return 0;
}