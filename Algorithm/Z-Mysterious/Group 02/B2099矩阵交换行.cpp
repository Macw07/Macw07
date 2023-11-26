#include <iostream>
#include <algorithm>
using namespace std;

int arr[10][10];

int main(){
    for (int i=1; i<=5; i++){
        for (int j=1; j<=5; j++){
            cin >> arr[i][j];
        }
    }
    int o, t;
    cin >> o >> t;
    for (int j=1; j<=5; j++){
        swap(arr[o][j], arr[t][j]);
    }
    for (int i=1; i<=5; i++){
        for (int j=1; j<=5; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}