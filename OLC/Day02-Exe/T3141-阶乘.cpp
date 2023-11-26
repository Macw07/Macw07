#include <iostream>
using namespace std;

int n;

long long rec(int k){
    if (k == 1){
        return 1;
    }
    return  k * rec(k-1);
}

int main(){
    cin >> n;
    cout << rec(n) << endl;
    return 0;
}