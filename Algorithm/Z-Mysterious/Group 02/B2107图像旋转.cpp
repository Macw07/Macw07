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
    // 旋转90度输出
    for (int i=1; i<=m; i++){
        for (int j=n; j>=1; j--){
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}