#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n, base;
    cin >> n >> base;
    base *= -1;
    string s;
    printf("%d=", n);
    bool flag = 1;
    if (n < 0){
        flag = 0;
        n *= -1;
    }
    while (n){
        if (n % base >= 10){
            s += (n % base)-10+'A';
        } else{
            s += n % base + '0';
        }
        n /= base;

    }
    reverse(s.begin(), s.end());
    cout << s;
    printf("(base-%d)", base);
    return 0;
}