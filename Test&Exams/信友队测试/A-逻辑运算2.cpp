#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    if (n % 5 == 0) cout << "YES" << endl;
    else if (n % 3 == 0 && n <= 20) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}