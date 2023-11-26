#include <iostream>
using namespace std;

long long a, b, c;

int main(){
    cin >> a >> b >> c;
    if (a + b + c <= 100){
        if (b % 5 == 0){
            if (c % 7 == 0){
                if (a-b > b-c){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}