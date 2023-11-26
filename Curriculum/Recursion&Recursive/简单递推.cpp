#include <iostream>
using namespace std;

int main(){
    int fib[1000] = {0, 1};
    for (int i=2; i<=8; i++){
        fib[i] = fib[i-1]+fib[i-2];
    }
    cout << fib[8] << endl;
    return 0;
}