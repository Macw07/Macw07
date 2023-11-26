#include <iostream>
using namespace std;

int arr[10005] = {};

int main(){
    int n, k;
    cin >> n >> k;
    for (int i=0; i<k; i++){
        cin >> arr[i];
    }
    bool flag = 1;
    for (int i=0; i<k; i++){
        if (arr[i] > n && flag){
            cout << n << " ";
            flag = 0;
        }
        cout << arr[i] << " ";
    }
    if (flag){
        cout << n;
    }
    return 0;
}