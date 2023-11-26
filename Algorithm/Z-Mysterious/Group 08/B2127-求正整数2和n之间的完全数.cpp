#include <iostream>
using namespace std;

int n;

int sum_factors(int n){
    int total = 0;
    for (int i=1; i<n; i++){
        if (n % i == 0){
            total += i;
        }
    }
    return total;
}

int main(){
    cin >> n;
    for (int i=2; i<=n; i++){
        if (sum_factors(i) == i){
            cout << i << endl;
        }
    }
    return 0;
}