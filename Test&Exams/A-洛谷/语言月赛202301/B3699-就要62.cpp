#include <iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;
    if (n % 62 == 0){
        cout << "Yes" << endl;
        return 0;
    }
    while(n){
        if (n % 10 == 2 && n / 10 % 10 == 6) {
            cout << "Yes" << endl;
            return 0;   
        }
        n /= 10;
    }
    cout << "No" << endl;
    return 0;
}