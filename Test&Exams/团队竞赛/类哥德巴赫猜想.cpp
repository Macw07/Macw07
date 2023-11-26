#include <iostream>
using namespace std;

bool isNotPrime(int num1){
    bool flag = 0;
    for (int i=2; i*i <= num1; i++){
        if (num1 % i == 0){
            return true;
        }
    }
    return false;
}

int main(){
    int N;
    cin >> N;
    for (int i=3; i<=N; i++){
        bool res1 = isNotPrime(i);
        bool res2 = isNotPrime(N-i);
        if (res1 && res2){
            cout << i << " " << N-i << endl;;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
