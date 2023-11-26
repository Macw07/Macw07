#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    freopen("testcase009.in", "w", stdout);
    srand(time(NULL));
    int n = rand()%1000 + 1;
    int m = rand()%1000 + 1;
    n = 1000, m = 1000;
    int s = rand()%n + 1;
    int e = rand()%m + 1;
    cout << n << " " << m << " " << s << " " << e << endl;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            int a = rand()%n + 1;
            int b = rand()%m + 1;
            cout << a << " " << b << " ";
        }
        cout << endl;
    }
    return 0;
}