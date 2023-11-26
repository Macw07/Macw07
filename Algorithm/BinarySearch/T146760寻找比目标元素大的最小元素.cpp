#include <iostream>
using namespace std;

int arr[2000];

int main(){
    int n, t;
    cin >> n >> t;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    int l=-1, r=n;
    while (l+1 != r){
        int m = (l+r)/2;
        if (arr[m] <= t){
            l = m;
        } else{
            r = m;
        }
    }
    cout << arr[r] << endl;
    return 0;
}