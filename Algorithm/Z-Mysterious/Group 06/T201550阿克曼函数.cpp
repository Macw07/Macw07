#include <iostream>
using namespace std;

int m, n;

int Ackmann(int m, int n){
    if (m == 0) return n+1;
    if (m > 0 && n == 0) return Ackmann(m-1, 1);
    if (n > 0) return Ackmann(m-1, Ackmann(m, n-1));
    return 0;
}

int main(){
    cin >> m >> n;
    cout << Ackmann(m, n) << endl;
    return 0;
}