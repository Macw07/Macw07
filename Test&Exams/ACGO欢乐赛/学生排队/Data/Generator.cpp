#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    // srand(time(NULL));
    freopen("case010.in", "w", stdout);
    // int n = rand() % 1000000 + 1;
    // cout << n << endl;
    // for (int i=1; i<=n; i++){
    //     int t = rand() % 10000000 + 1;
    //     cout << t << " ";
    // }
    cout << 500000 << endl;
    for (int i=1; i<=500000; i++){
        cout << 500000 - i << " ";
    }
    return 0;
}