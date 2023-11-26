#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    freopen("testcase020.in", "w", stdout);
    srand(time(NULL));
    int a = rand() % 5000;
    int b = rand() % 5000;
    cout << a << " " << b;
    return 0;
}