#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    freopen("testcase010.in", "w", stdout);
    srand(time(NULL));
    int n = rand() % 500 + 25;
    int m = rand() % 50 + 1;
    cout << n << " " << m << endl;
    for (int i=1; i<=m; i++){
        int t = n-20 + rand()%40;
        cout << t << " ";
    }
    return 0;
}