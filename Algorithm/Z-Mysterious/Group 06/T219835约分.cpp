#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (a % b == 0){
        return b;
    }
    return gcd(b, a % b);
}

int main(){
    int a, b, g;
    scanf("%d:%d", &a, &b);
    g = gcd(a, b);
    printf("%d:%d", a/g, b/g);
    return 0;
}