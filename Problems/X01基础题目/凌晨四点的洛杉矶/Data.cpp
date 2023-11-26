#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main(){
    freopen("testcase010.in", "w", stdout);
    srand(time(NULL));
    int n = rand() % 5000 + 10;
    cout << n << endl;
    while(n--){
        int h = rand() % 24;
        int m = rand() % 60;
        if (h < 10) cout << 0;
        cout << h << ":";
        if (m < 10) cout << 0;
        cout << m << endl;
    }
    int h = rand() % 24;
    int m = rand() % 60;
    if (h < 10) cout << 0;
    cout << h << ":";
    if (m < 10) cout << 0;
    cout << m << " ";

    int h2 = rand() % (24-h) + h;
    int m2 = rand() % (60-m) + m;
    if (h2 < 10) cout << 0;
    cout << h2 << ":";
    if (m2 < 10) cout << 0;
    cout << m2 << endl;
    return 0;
}