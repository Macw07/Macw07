#include <iostream>
#include <algorithm>
using namespace std;

int n;
bool isPrime(int k){
    if (k <= 1) return 0;
    if (k == 2) return 1;
    for (int i=2; i*i<=k; i++){
        if (k % i == 0) return 0;
    }
    return 1;
}

int main(){
    cin >> n;
    for (int i=2; i<=n; i++){
        if (n % i == 0 && isPrime(i)){
            cout << n/i << endl;
            return 0;
        }
    }
    return 0;
}