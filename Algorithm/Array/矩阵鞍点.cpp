/* 给定一个5×5的矩阵，每行只有一个最大值，每列只有一个最小值，寻找这个矩阵的鞍点。
鞍点指的是矩阵中的一个元素，它是所在行的最大值，并且是所在列的最小值。 */

#include <iostream>
using namespace std;

int arr[5][5] = {};

int main(){
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            cin >> arr[i][j];
        }
    }
    int max_arr[5] = {};
    int min_arr[5] = {};
    for (int i=0; i<5; i++){
        int max=0;
        int min=100;
        for (int j=0; j<5; j++){
            if (arr[i][j]>max){
                max = arr[i][j];
            }
        }  
        for (int j=0; j<5; j++){
            if (arr[j][i] < min){
                min = arr[j][i];
            }
        }  
        max_arr[i] = max;
        min_arr[i] = min;
    }
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            if (max_arr[i] == min_arr[j]){
                cout << i+1 << " " << j+1 << " " << max_arr[i];
                return 0;
            }
        }
    }
    cout << "not found" << endl;
    return 0;
}