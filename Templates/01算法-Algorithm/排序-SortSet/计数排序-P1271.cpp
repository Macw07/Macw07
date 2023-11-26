#include <iostream>
using namespace std;

int arr[1000] = {};

int main(){
    int n, m, t;
    cin >> n >> m;
    for (int i=0; i<m; i++){
        cin >> t;
        arr[t-1] += 1;
    }
    for (int i=0; i<1000; i++){
        while (arr[i]>0){
            cout << i+1 << " ";
            arr[i]--;
        }
    }
    return 0;
}