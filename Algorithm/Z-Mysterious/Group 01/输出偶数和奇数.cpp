/* 输入n个整数，将其中的偶数和奇数分别显示出来（1 < n < 30） */
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=0; i<n; i++){
        if (arr[i] % 2 == 0){
            cout << arr[i] << " ";
        }
    }
    cout << endl;
    for (int i=0; i<n; i++){
        if (arr[i] % 2 == 1){
            cout << arr[i] << " ";
        }
    }
}