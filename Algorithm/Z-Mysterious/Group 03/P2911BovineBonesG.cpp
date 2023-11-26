#include <iostream>
using namespace std;

int arr[105] = {};

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    for (int i=1; i<=a; i++){
        for (int j=1; j<=b; j++){
            for (int k=1; k<=c; k++){
                arr[i+j+k] += 1;
            }
        }
    }
    int max=0, max_index=0;
    for (int i=1; i<=100; i++){
        if(arr[i] > max){
            max = arr[i];
            max_index = i;
        }
    }
    cout << max_index << endl;
    return 0;
}