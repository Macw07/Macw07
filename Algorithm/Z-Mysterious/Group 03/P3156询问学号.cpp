#include <iostream>
using namespace std;

long arr[2000005] = {};

int main(){
    int n, m, t;
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
    for (int i=1; i<=m; i++){
        cin >> t;
        cout << arr[t] << endl;
    }
    return 0;
}