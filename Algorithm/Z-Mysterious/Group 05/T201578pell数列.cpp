#include <iostream>
using namespace std;

int arr[1000005];
int ccount[1000005];

int main(){
    int n;
    cin >> n;
    arr[1] = 1;
    arr[2] = 2;
    for (int i=1; i<=n; i++){
        cin >> ccount[i];
    }
    int max=0;
    for (int i=1; i<=n; i++){
        if (ccount[i] > max){
            max = ccount[i];
        }
    }
    for (int i=3; i<=max; i++){
        arr[i] = (2*arr[i-1]+arr[i-2])%32767;
    }
    for (int i=1; i<=n; i++){
        cout << arr[ccount[i]] << endl;
    }
    return 0;
}