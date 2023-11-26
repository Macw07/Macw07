#include <iostream>
using namespace std;

int main(){
    int arr[55], n, q;
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        if (c > arr[a]){
            cout << "INVALID" << endl;
            continue;
        }
        arr[a] -= c;
        arr[b] += c;
        for (int i=1; i<=n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}