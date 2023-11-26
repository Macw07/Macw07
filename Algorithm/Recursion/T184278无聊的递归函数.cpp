#include <iostream>
using namespace std;

int f91(int n){
    if (n >= 101) {
        return n-10;
    }
    return f91(f91(n+11));
}

int main(){
    int n;
    cin >> n;
    printf("f91(%d) = ", n);
    cout << f91(n);
    return 0;
}