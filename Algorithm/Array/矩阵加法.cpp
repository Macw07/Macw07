#include <iostream>
using namespace std;

int arr1[105][105] = {};
int arr2[105][105] = {};

int main(){
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> arr1[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> arr2[i][j];
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << arr2[i][j] + arr1[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}