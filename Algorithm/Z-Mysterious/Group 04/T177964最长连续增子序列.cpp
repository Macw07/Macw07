#include <iostream>
using namespace std;

int arr[1005] = {};

int main(){
    int n, result=1, length=1;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=1; i<=n; i++){
        if (length > result){
            result = length;
        }
        if (arr[i]>arr[i-1]){
            length++;
        } else{
            length = 1;
        }
    }
    cout << result;
    return 0;
}