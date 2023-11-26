#include <iostream>
#include <algorithm>
using namespace std;

int n, m, t;

int main(){
    cin >> n >> m;
    int total = 0, segment = 1;
    for (int i=1; i<=n; i++) {
        cin >> t;
        total += t;
        if (total > m){
            segment += 1;
            total = t;
        }
    }
    cout << segment << endl;
    return 0;
}