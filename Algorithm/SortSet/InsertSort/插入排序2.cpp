// 插入排序算法
#include <iostream>
using namespace std;

int arr[100] = {};
int main(){
    int n, min=0;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=1; i<n; i++){
        int j=i;
        int t=arr[i];
        while(t<arr[j-1] && j>0){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = t;
    }
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}