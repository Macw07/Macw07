#include <iostream>
using namespace std;

bool prime(int n){
    if (n == 2) return true;
    for (int i=2; i*i<=n; i++){
        if (n % i == 0) return false;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    // cout << prime(n) << endl;
    for (int i=2; i<=n; i++){
        if (!prime(i)) continue;
        for (int j=2; j<=n-i; j++){
            if (!prime(j)) continue;
            for (int k=2; k<=n-i-j; k++){
                if (!prime(k)) continue;
                if (i + j + k == n){
                    printf("%d %d %d\n", i, j, k);
                    return 0;
                }
            }
        }
    }
    return 0;
}