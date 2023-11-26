#include <iostream>
using namespace std;

long long arr[10000] = {};
int narr[10000] = {};

int main(){
    int n, max=0;
    cin >> n;
    arr[0] = 1;
    arr[1] = 1; 
    for (int i=0; i<n; i++){
        cin >> narr[i];
        if (narr[i]>max){
            max = narr[i];
        }
    }
    for (int i=2; i<max; i++){
        arr[i] = (arr[i-1]+arr[i-2])%1000;
    }
    for (int i=0; i<n; i++){
        cout << arr[narr[i]-1] << endl;
    }
    return 0;
}