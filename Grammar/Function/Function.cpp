#include <iostream>
using namespace std;

int multiply(int a, int b);

int main(){
    int res;
    res = multiply(10,20);
    std:cout << res << "\n";
}

int multiply(int a, int b) {
    return a*b;
}