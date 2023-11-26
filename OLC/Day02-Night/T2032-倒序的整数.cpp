#include <iostream>
using namespace std;

long long n;

void rec(long long number){
    if (!number) return ;
    cout << number % 10;
    rec(number/10);
    return ;
}

int main(){
    cin >> n;
    rec(n);
    return 0;
}