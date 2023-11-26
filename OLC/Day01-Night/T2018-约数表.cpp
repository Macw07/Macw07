#include <iostream>
#include <algorithm>
using namespace std;

int n, q, t;

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            if (i % j == 0) cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}