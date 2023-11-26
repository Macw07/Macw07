#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, t;
    cin >> n;
    for (int i=n; i>=0; i--){
        cin >> t;
        if (t){
            if (i!=n&&t>0) cout << "+";
            if (abs(t)>1||i==0) cout << t;
            if (t==-1&&i) cout << "-";
            if (i>1) cout << "x^" << i;
            if (i == 1) cout << "x";
        }
    }
    return 0;
}