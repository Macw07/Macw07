#include <iostream>
using namespace std;

long long n, cnt = 1;

int main(){
    cin >> n;
    while(n != 1){
        if (n % 2 == 1) n = n * 3 + 1;
        else n /= 2;
        cnt += 1;
    }
    cout << cnt << endl;
    return 0;
}