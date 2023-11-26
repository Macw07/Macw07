#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int xi, yi, xj, yj;
    cin >> xi >> yi >> xj >> yj;
    int dis = abs(xi-xj) + abs(yi-yj);
    cout << dis << endl;
    return 0;
}