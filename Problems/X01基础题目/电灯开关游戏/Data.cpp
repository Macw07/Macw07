#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;

int main(){
    freopen("testcase010.in", "w", stdout);
    srand(time(NULL));
    int n = rand() % 5000 + 10;
    int m = rand() % 5000 + 10;
    cout << n << " " << m << endl;
    while(m--){
        int k = rand() % n + 1;
        cout << k << " ";
    }
    return 0;
}