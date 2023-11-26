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
    int n, k;
    cin >> n >> k;
    bool flag = 0;
    for (int i=2; i<=n-k; i++){
        if (prime(i) && prime(i+k)){
            flag = 1;
            cout << i << " " << i+k << endl;
        }
    }
    if (flag == 0){
        cout << "empty" << endl;
    }
    return 0;
}