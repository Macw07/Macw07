#include <iostream>
using namespace std;

int n;

int fib(int n){
    if (n == 1 || n == 0) return n;
    return fib(n-1)+fib(n-2);
}

int main(){
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}