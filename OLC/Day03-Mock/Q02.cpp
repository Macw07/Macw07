#include <iostream>
using namespace std;

int main(){
    int n, ans;
    scanf("%d", &n);
    ans = (n+1) % 7;
    printf("%d\n", ans + 1);
    return 0;
}