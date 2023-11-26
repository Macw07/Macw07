// 冒泡排序
#include <iostream>
using namespace std;

int n, arr[10005];

int main(){
    cin >> n;
    int count = 0;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                count += 1;
            }
        }
    }
    // for (int i=0; i<n; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    cout << count;
    return 0;
}