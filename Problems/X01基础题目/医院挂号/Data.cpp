#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(NULL));
    freopen("testcase005.in", "w", stdout);
    int n = rand() % 5000 + 1, m = rand() % n;
    cout << n << " " << m << endl;
    while(m--){
        int a = rand() % n + 1;
        n -= 1;
        cout << a << endl;
    }
    int a = rand() % n + 1;
    cout << a << endl;
    return 0;
}