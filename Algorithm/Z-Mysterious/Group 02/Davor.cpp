#include <iostream>
using namespace std;

int main(){
    int n, x=0, k=0, d=0;
    cin >> n;
    for (int i=1; i<=364; i++){
        if (d==7) d=0;
        x++;
        k += d;   
        d++;
    }
    // cout << x << " " << k << endl;
    for (int i=1; i<=100; i++){
        for (int j=0; j<=100; j++){
            if (j*x + k*i == n){
                cout << j << "\n" << i;
                return 0;
            }
        }
    }
    return 0;
}