#include <iostream>
using namespace std;

int arr[505] = {0}, n, i, t;

int main(){
    cin >> n;
    for (i=1; i<=n; i++){
        cin >> t;
        arr[t]++;
    }
    for (i=n; i>0; i--){
        if (arr[i] == i){
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}