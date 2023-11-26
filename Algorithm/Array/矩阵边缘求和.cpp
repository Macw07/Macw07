/* 给出一个n行m列的矩阵，计算其中位于边缘的元素之和 */

#include <iostream>
using namespace std;

int arr[50][50] = {};

int main(){
    int row, column, sum=0;
    cin >> row >> column;
    for (int i=0; i<row; i++){
        for (int j=0; j<column; j++){
            cin >> arr[i][j];
        }
    }
    for (int i=0; i<row; i++){
        for (int j=0; j<column; j++){
            if (i==0 or i==row-1 or j==0 or j==column-1){
                    sum += arr[i][j];
            }
        }
    }
    cout << sum;
}