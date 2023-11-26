#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int triangle[25][25] = {};
    triangle[1][1] = 1;
    cout << 1 << endl;
    for (int i=2; i<=n; i++){
        for (int j=1; j<=i; j++){
            triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}