#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int total = 0;
double n, k, l, c, d, p, nl, np;

int main(){
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    total = min(floor(k*l/nl), min(floor(p/np), c*d));
    cout << int(total/n) << endl;
    return 0;
}