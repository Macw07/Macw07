#include <iostream>
using namespace std;

bool prime(int k){
    if (k == 1) return 0;
    for (int i=2; i*i<=k; i++){
        if (k % i == 0) return 0;
    }
    return 1;
}

int main(){
    int n;
    cin >> n;
    for (int i=n; i>=2; i--){
        if (prime(i) && n%i == 0 && prime(n/i)){
            cout << i << endl;
            break;
        }
    }
    return 0;
}