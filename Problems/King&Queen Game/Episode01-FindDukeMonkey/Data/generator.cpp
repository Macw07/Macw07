#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    freopen("testcase020.in", "w", stdout);
    srand(time(NULL));
    int n = rand()%12 + 3;
    int m = rand()%12 + 3;
    n = 15;
    m = 15;
    char arr[30][30] = {};
    cout << n << " " << m << endl;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            int k = rand()%10 + 1;
            if (k < 3) arr[i][j] = '#';
            else arr[i][j] = '.';
        }
    }
    int a = rand()%n + 1;
    int b = rand()%m + 1;
    arr[a][b] = '&';
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}