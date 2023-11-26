#include <iostream>
using namespace std;

int a, b, l;
int a1, b1;

int gcd(int a, int b){
    if (a % b == 0) return b;
    return gcd(b, a % b);
}
int main(){
    cin >> a >> b >> l;
    a1 = l, b1 = 1;
    for (int i=1; i<=l; i++){
        for (int j=1; j<=l; j++){
            if (gcd(i, j) == 1 && i * b >= j * a && i * b1 < j * a1){
                a1 = i;
                b1 = j;
            }
        }
    }
    cout << a1 << " " << b1 << endl;
    return 0;
}