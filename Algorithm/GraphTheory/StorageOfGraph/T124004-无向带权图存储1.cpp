#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[105][105];

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    memset(arr, 0x7f, sizeof arr);
    for (int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = arr[b][a] = min(arr[a][b], c);
    }
    for (int i=0; i<q; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if (c < arr[a][b] || arr[a][b] == 0){
            cout << "Accepted" << endl;
        } else{
            cout << "Cancel" << endl;
        }
    }
    return 0;
}