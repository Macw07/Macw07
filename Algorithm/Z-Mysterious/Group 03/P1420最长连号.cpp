#include <iostream>
using namespace std;

int arr[1005] = {};

int main(){
    int n, max=1, temp=1;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=0; i<n-1; i++){
        if (arr[i]+1 == arr[i+1]){
            temp++;
        } else{
            if (temp > max){
                max = temp;
            }
            temp = 1;
        }
    }
    if (temp > max){
        max = temp;
    }
    cout << max;
    return 0;
}