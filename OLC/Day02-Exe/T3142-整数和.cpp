#include <iostream>
using namespace std;

int n;

int rec(int k){
    if (k == n){
        return k;
    }
    return k + rec(k+1);
}

int main(){
    cin >> n;
    cout << rec(1) << endl;
    return 0;
}