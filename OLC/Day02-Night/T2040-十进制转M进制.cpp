#include <iostream>
using namespace std;

int n, m;

void convert(int n, int m){
    if (!n) return ;
    convert(n / m, m);
    if (n % m >= 10) cout << char('A' + (n % m) - 10);
    else cout << n % m;
    return ;
}

int main(){
    cin >> n >> m;
    convert(n, m);
    return 0;
}