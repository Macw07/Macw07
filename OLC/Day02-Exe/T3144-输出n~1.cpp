#include <iostream>
using namespace std;

int n;

void rec(int k){
    if (k == n){
        cout << k << endl;
        return ;
    }
    rec(k+1);
    cout << k << endl;
    return ;
}

int main(){
    cin >> n;
    rec(1);
    return 0;
}