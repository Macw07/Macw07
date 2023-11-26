#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int a, b, c, d;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

int dis(int a, int b, int c, int d){
    return abs(c - a) + abs(d - b);
}

int main(){
    cin >> a >> b >> c >> d;
    if (dis(a, b, c, d) >= 6) cout << "Arisu" << endl;
    else cout << "Midori" << endl;
    return 0;
}