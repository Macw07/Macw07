#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long t;
unsigned long long n, ans;
unsigned long long sets[3000020];

int main(){
    cin >> t;
    for (long long i=1; i<=3000019; i++){
        sets[i] = sets[i-1] + i*i;
    }
    while(t--){
        cin >> n;
        ans = 0;
        if (n == 2) {
            cout << 3 << endl;
            continue;
        }
        if (n == 1){
            cout << 0 << endl;
            continue;
        }
        ans += sets[n-1];
        ans += n*(n-1);
        cout << ans << endl;
    }
    return 0;
}