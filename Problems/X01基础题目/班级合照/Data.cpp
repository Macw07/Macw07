#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(NULL));
    freopen("testcase005.in", "w", stdout);
    int n = rand()%5000 + 1;
    cout << n << endl;
    while(n--){
        int a = rand() % 2;
        int b = rand() % 500 + 1;
        cout << a << " " << b << endl;
    }
    return 0;
}