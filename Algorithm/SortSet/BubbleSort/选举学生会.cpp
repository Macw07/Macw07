// 每张选票都写了一个候选人编号。
// 现在想把这些堆积如山的选票按照投票数字从小到大排序。

#include <iostream>
using namespace std;

int arr[1005] = {};

int main(){
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++){
        cin >> arr[i];
    }
    for (int i=0; i<m-1; i++){
        for (int j=0; j<m-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    for (int i=0; i<m; i++){
        cout << arr[i] << " ";
    }
}