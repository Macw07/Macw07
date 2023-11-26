#include <iostream>
using namespace std;

int recursion(int n){
    if (n == 1||n==2){
        return 1;
    }
    return recursion(n-1)+recursion(n-2);
}

int main(){
    int m;
    cin >> m;
    cout << recursion(m);
    return 0;
}