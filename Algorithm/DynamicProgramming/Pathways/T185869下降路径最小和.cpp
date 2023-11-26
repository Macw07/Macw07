#include <iostream>
#include <algorithm>
using namespace std;

int arr[505][505];

int fmin(int a, int b, int c){
    if (a > b){
        swap(a, b);
    }
    if (b > c){
        swap(b, c);
    }
    if (a > b){
        swap(a, b);
    }
    return a;
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    // 通过min函数找出最小值
    for (int i=n-2; i>=0; i--){
        for (int j=0; j<m; j++){
            if (j == 0){
                arr[i][j] += min(arr[i+1][j], arr[i+1][j+1]);
                continue;
            }
            if (j == m-1){
                arr[i][j] += min(arr[i+1][j], arr[i+1][j-1]);
                continue;
            }
            arr[i][j] += fmin(arr[i+1][j-1], arr[i+1][j], arr[i+1][j+1]);
        }
    }
    int minimum = 0x7f7f7f;
    for (int j=0; j<m; j++){
        // cout << arr[0][j] << " ";
        if (arr[0][j] < minimum){
            minimum = arr[0][j];
        }
    }
    cout << minimum << endl;
    return 0;
}