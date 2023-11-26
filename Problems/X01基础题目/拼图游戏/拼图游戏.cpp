#include <iostream>
using namespace std;

int main(){
    int n, t;
    int arr[5] = {};
    cin >> n;
    while(n--){
        cin >> t;
        if (t <= 3){
            arr[1]++;
        } else if (t <= 7){
            arr[2]++;
        } else {
            arr[3]++;
        }
    }
    cout << "简单=" << arr[1] << endl;
    cout << "中等=" << arr[2] << endl;
    cout << "困难=" << arr[3] << endl;
    return 0;
}