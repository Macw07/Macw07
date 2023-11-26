#include <iostream>
using namespace std;

int main(){
    int arr[1005] = {}, n, max=0, min=0x7f7f7f, t;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> t;
        if (t>max){
            max = t;
        }
        if(t<min){
            min = t;
        }
    }
    cout << max-min;
    return 0;
}