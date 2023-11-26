#include <iostream>
#include <cmath>
using namespace std;

long long t, n, k;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        if (k >= 30 || n < pow(2, k)) cout << n + 1 << endl;
        else cout << int(pow(2, k)) << endl;
    }
    return 0;
}