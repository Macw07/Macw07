#include <iostream>
using namespace std;

int main(){
    long long n, t, last;
    long long total = 0;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> t;
        if (i == 1) last = t;
        if (last != t){
            last = t;
            total += 1;
        }
    }
    cout << "Ans=" << total << endl;
    return 0;
}