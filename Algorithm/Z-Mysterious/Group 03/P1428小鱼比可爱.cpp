#include <iostream>
using namespace std;

int arr[105] = {};

int main(){
    int n, count;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=0; i<n; i++){
        count = 0;
        for (int j=0; j<i; j++){
            if (arr[j] < arr[i]){
                count++;
            }
        }
        cout << count << " ";
    }
    return 0;
}