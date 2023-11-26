#include <iostream>
using namespace std;

long long gcd(long long a, long long c){
    long long t;
    while (a%c!=0){
        t = c;
        c = a%c;
        a = t;
    }
    return c;
}

int main(){
    long long a, b, c, t;
    cin >> a >> b >> c;
    if (a>b){
        t = a;
        a = b;
        b = t;
    }
    if (b>c){
        t = b;
        b = c;
        c = t;
    }
    if (a>b){
        t = a;
        a = b;
        b = t;
    }
    long long gc = gcd(a, c);
    printf("%lld/%lld", a/gc, c/gc);
    return 0;
}