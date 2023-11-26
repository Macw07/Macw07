#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    if (n > 0) printf("%d", n%2023);
    else printf("%d", 2023+n%2023);
    return 0;   
}