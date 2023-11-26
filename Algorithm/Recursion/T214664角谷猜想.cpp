#include <iostream>
using namespace std;

void recursion(int n){
    if (n == 1) {
        printf("1\n"); 
        return;
    }
    if (n%2 == 1){
        printf("3*%d+1=%d\n", n, 3*n+1);
        recursion(3*n+1);
    } else{
        printf("%d/2=%d\n", n, n/2);
        recursion(n/2);
    }
}

int main(){
    int n;
    cin >> n;
    recursion(n);
    return 0;   
}