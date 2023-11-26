/* 小码君想去买两根棍子，他来到商店里发现有n根棍子，第i根棍子的长度为Li。
他希望买下的两根棍子长度差值尽可能小，请你帮他找到最合适的两根棍子，并输出他们的差值。 */

#include <iostream>
using namespace std;

int arr[105] = {};

int main(){
    int num;
    cin >> num;
    for (int i=0; i<num; i++){
        cin >> arr[i];
    }
    for (int i=0; i<num; i++){
        for (int j=0; j<num-1-i; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    // cout << '\n';
    int sub = 10001;
    for (int i=0; i<num-1; i++){
        if (arr[i+1] - arr[i] <= sub){
            // cout << arr[i+1] << ' ' << arr[i] << endl;
            sub = arr[i+1] - arr[i];
        }
    }
    
    cout << sub << endl;
}