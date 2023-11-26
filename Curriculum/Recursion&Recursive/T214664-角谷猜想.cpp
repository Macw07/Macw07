#include <iostream>
using namespace std;

int n;

void recursion(int n){
    if (n == 1) {
        printf("1"); 
        return;
    }
    if (n % 2 == 0){
        printf("%d/2=%d\n", n, n/2);
        recursion(n/2);
        return;
    } else{
        printf("3*%d+1=%d\n", n, n*3+1);
        recursion(n*3+1);
        return;
    }
}

int main(){
    cin >> n;
    recursion(n);
    return 0;
}