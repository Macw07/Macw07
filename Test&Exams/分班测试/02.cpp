#include <stdio.h>
#include <cmath>
using namespace std;

int n, total;
int a, b, c;

int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d %d %d", &a, &b, &c);
        total += abs(a-b) - c;
    }
    printf("%d", total);
    return 0;
}