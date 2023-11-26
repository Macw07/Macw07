#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    cout << ((n % 4 == 0 && (n % 100 != 0 || n % 400 == 0)) ? "Y" : "N");
    return 0;
}