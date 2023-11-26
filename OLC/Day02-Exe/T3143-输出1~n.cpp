#include <iostream>
using namespace std;

int n;

void rec(int k){
    if (k == n){
        cout << k;
        return ;
    }
    cout << k << endl;
    rec(k+1);
    return ;
}

int main(){
    cin >> n;
    rec(1);
    return 0;
}