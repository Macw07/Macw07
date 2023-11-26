// 选择排序

#include <iostream>
using namespace std;

int arr[100] = {};
int main(){
    int n, min=0;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=0; i<n; i++){
        min = i;
        for (int j=i+1; j<n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}