// 输入 n（0 < n ≤ 100），再输入 n 个数，将这 n 个数经过一趟选择将最小值和第 1 个元素交换。
// 题目保证所有数据均在 int 的表示范围内。

#include <iostream>
using namespace std;

int arr[105] = {};

int main(){
    // Initiation
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    // Find the Max Value
    int min = 0x7f7f7f7f;
    int index = 0;
    for (int i=0; i<n; i++){
        if (arr[i] < min){
            min = arr[i];
            index = i;
        }
    }
    swap(arr[0], arr[index]);
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}