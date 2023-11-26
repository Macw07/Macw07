// 求出a^b的末尾3位数是多少？

#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int x = 1;
    for (int i=1; i<=b; i++){
        x *= a;
        x = x % 1000;
    }
    if (x<10){
        cout << "00";
    } else if (x<100){
        cout << "0";
    }
    cout << x;
}