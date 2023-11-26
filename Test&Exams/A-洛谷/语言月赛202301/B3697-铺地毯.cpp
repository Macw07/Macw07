#include <iostream>
using namespace std;

int main(){
    unsigned long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    if (a == 0 || b == 0 || c == 0){
        printf("0");
        return 0;
    }
    if (a % c == 0 && b % c == 0){
        printf("%lld", (a/c) * (b/c));
    } else{
        printf("-1");
    }
    return 0;
}