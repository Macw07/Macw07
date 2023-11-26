#include <iostream>
using namespace std;

bool isPerfectSquare(int n);

int main(){
    int m, n, max=-0x7f7f7f;
    cin >> m;
    for (int i=0; i<m; i++){
        cin >> n;
        if(!isPerfectSquare(n) && n>max){
            max = n;
        }
    }
    cout << max;
    
    return 0;
}

bool isPerfectSquare(int n){
    if (n<0){
        return 0;
    }
    for (int i=0; i*i<=n; i++){
        if (i*i==n){
            return 1;
        }
    }
    return 0;
}