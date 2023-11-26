#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, a = 0, b = 0;
    cin >> n;
    while(n != 1){
        if (n % 2 == 0) n /= 2, a++;
        else n = n*3 + 1, b++;
    }
    cout << a << endl << b+1 << endl;
    return 0;
}