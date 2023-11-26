#include <iostream>
using namespace std;

int arr[105][105];

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    for (int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    for (int i=0; i<q; i++){
        int a, b;
        cin >> a >> b;
        if (arr[a][b] || arr[b][a]){
            cout << "Cancel" << endl;
        } else{
            cout << "Accepted" << endl;
        }
    }
    return 0;
}