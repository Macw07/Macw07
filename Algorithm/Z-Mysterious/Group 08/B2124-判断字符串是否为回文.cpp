#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string a, b;
    cin >> a;
    b = a; reverse(b.begin(), b.end());
    if (a == b) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}