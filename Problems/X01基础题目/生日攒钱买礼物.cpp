#include <iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long total = 0;
    for (int i=1; i<=n; i++){
        total += i;
    }
    // long long total = (n+1)*n/2;  // 高斯求和
    cout << total << endl;
    return 0;
}