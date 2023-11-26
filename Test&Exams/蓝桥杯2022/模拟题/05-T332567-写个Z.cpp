#include <iostream>
#include <algorithm>
using namespace std;

int n;  // 代表图案的长和宽

int main(){
    cin >> n;
    for (int i=0; i<n; i++) cout << '*';
    cout << endl;

    for (int i=1; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            cout << ' ';
        }
        cout << '*' << endl;
    }

    for (int i=0; i<n; i++) cout << '*';
    cout << endl;
    return 0;
}