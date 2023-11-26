// 在一个 n∗n 的矩阵当中，查询(x,y)的所在行，所在列，所在对角线的所有坐标。

#include <iostream>
using namespace std;

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    int arr[n][n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            arr[i][j] = j+1;
        }
    }
    for (int i=1; i<=n; i++){
        cout << '(' << x << ',' << i << ')' << ' ';
    }
    cout << endl;
    for (int i=1; i<=n; i++){
        cout << '(' << i << ',' << y << ')' << ' ';
    }
    cout << endl;
    int temp_x=x, temp_y = y;
    while (temp_x && temp_y){
        temp_x--;
        temp_y--;
    }
    // cout << temp_x << " " << temp_y << endl;
    for (int i=temp_x, j=temp_y; i<n && j<n; i++, j++){
        cout << '(' << i+1 << ',' << j+1 << ')' << ' ';
    }
    cout << endl;
    temp_x=x, temp_y = y;
    while (temp_x && temp_y<n){
        temp_x--;
        temp_y++;
    }
    // cout << temp_x << " " << temp_y << endl;
    for (int i=temp_x, j=temp_y; i<=n && j>0; ++i, j--){
        if (i==0){
            continue;
        }
        cout << '(' << i << ',' << j << ')' << ' ';
    }
}