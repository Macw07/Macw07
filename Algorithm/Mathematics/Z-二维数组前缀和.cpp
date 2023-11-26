#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[105][105];
int preFix[105][105];

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            preFix[i][j] = preFix[i-1][j] + preFix[i][j-1] + arr[i][j] - preFix[i-1][j-1];
            cout << preFix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}