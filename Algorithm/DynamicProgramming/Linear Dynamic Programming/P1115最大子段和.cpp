#include <iostream>
#include <algorithm>
using namespace std;

int arr[200005] = {};

int main(){
    int n, count=0, result=-0x7f7f7f;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=0; i<n; i++){
        count += arr[i];
        if (count > result){
            result = count;
        }
        if (count <= 0){
            count = 0;
        }
    }
    cout << result;
    return 0;
}