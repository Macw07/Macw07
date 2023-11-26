#include <iostream>
using namespace std;

int arr[10005] = {};

int main(){
    int n, i=0;
    cin >> n;
    arr[i] = n;
    while (n!=1){
        i++;
        if (n%2==0){
            n /= 2;
            arr[i] = n;
        } else if (i%2==1) {
            n = n*3+1;
            arr[i] = n;
        }
    }
    arr[i] = 1;
    for (int j=i; j>=0; j--){
        cout << arr[j] << " ";
    }
    return 0;
}