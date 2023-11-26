#include <iostream>
using namespace std;

int arr[105][105];

int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        // Rows
        for (int j=i; j<=n; j++){
            arr[i][j] = i;
        }
        // Columns
        for (int j=i; j<=n; j++){
            arr[j][i] = i;
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}