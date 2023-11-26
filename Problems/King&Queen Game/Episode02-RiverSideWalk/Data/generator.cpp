#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    // freopen("textcase020.in", "w", stdout);
    srand(time(NULL)); 
    int n = rand()%1000000 + 1;
    int k = rand()%200 + 1;
    cout << n << " " << k << endl;
    for (int i=1; i<=n; i++){
        int t = rand() % 200 + 1;
        cout << t << " ";
    }
    return 0;
}