#include <iostream>
using namespace std;

long long arr[105][105];

int main(){
    int n, m;
    cin >> n >> m;
    for (int j=0; j<=m; j++){
        arr[0][j] = 1;
    }
    for (int i=0; i<=n; i++){
        arr[i][0] = 1;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }
    cout << arr[n-1][m-1] << endl;
    return 0;
}