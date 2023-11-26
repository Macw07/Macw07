#include <iostream>
using namespace std;

int main(){
    int a, b, c, t;
    cin >> a >> b >> c;
    if (a==b && a==c){
        printf("%d %d %d", a, b ,c);
        return 0;
    }
    if (a > b){
        t = a;
        a = b;
        b = t;
    }
    if (b > c){
        t = c;
        c = b;
        b = t;
    }
    if (a > b){
        t = a;
        a = b;
        b = t;
    }
    printf("%d %d %d", a, b, c);
    return 0;
}