#include <iostream>
using namespace std;

int arr[105][105];

int main(){
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            int t;
            cin >> t;
            cout << t + arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}