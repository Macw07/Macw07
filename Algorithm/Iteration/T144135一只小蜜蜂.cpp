#include <iostream>
using namespace std;

long long arr[3][10000] = {};

int main(){
    int n, m=1, k=1;
    cin >> n;
    arr[0][0] = 1;
    arr[1][0] = 1; 
    for (int i=3; i<n+3; i++){
        if (i % 2 == 1){
            arr[0][m] = arr[1][m-1] + arr[0][m-1];
            // cout << arr[1][m-1] << " " << arr[0][m-1] << " " << arr[0][m] << endl;
            // cout << arr[0][m] << endl;
            m++;
        } else{
            arr[1][k] = arr[1][k-1] + arr[0][k];
            // cout << arr[1][k-1] << " " << arr[0][k] << " " << arr[1][k] << endl;
            k++;
        }
    }
    // for (int i=0; i<2; i++){
    //     for (int j=0; j<=n/2; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    if (n % 2 == 0){
        cout << arr[1][n/2-1];
    } else{
        cout << arr[0][n/2];
    }
    return 0;
}