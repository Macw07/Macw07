#include <iostream>
using namespace std;

int arr[100005] = {};
int arr2[100005] = {};
int main(){
    int n, t, m;
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=0; i<=100000; i++){
        for (int j=0; j<=m+3; j++){
            arr2[i] += arr[j]/(i+1);
        }
        if (arr2[i] < m){
            cout << i;
            // for (int k=0; k<=i; k++){
            //     cout << arr2[k] << ' ';
            // }
            return 0;
        }
    }
    return 0;
}