#include <iostream>
#include <algorithm>
using namespace std;

// 这题牛逼，还是一道数论

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", n / 3 + n % 3);
    return 0;
}