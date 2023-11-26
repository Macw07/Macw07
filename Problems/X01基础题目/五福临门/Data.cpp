#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    freopen("testcase012.in", "w", stdout);
    srand(time(NULL));
    // int t = rand() % 5000 + 1;
    // cout << t << endl;
    // while(t--){
    //     int n = rand() % 10000 + 1;
    //     cout << n << endl;
    //     for (int i=1; i<=n; i++){
    //         int t = rand() % 5 + 1;
    //         cout << t << " ";
    //     }
    //     cout << endl;
    // }
    cout << 1 << endl;
    cout << 30000000 << endl;
    for (int i=1; i<=5; i++){
        for (int j=1; j<=30000000/5; j++){
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}