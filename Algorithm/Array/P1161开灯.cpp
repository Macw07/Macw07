#include <iostream>
using namespace std;

int arr[2000000] = {};

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        double a;
        int t, ac;
        cin >> a >> t;
        for(int j=1; j<=t; j++){
            ac = a*j;
            if (arr[ac] == 1){
                arr[ac] = 0;
            } else{
                arr[ac] = 1;
            }
        }
    }
    for (int i=0; i<=2000000; i++){
        if (arr[i] == 1){
            cout << i;
            break;
        }
    }
    return 0;
}