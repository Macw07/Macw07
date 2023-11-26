#include <iostream>
using namespace std;

long long arr[100005] = {};
int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=0; i<n-2; i++){
        if (arr[i] < arr[i+1] && arr[i+1] > arr[i+2]){
            cout << "true";
            return 0;
        }
    }
    cout << "false";
    return 0;
}