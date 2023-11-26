#include <iostream>
#include <cmath>
using namespace std;

int n;

void recursion(int k){
    if (k == 0) return ;
    long long tmp = k;
    for (int i=log2(k)+1; i>=0; i--){
       long long t1 = pow(2, i);
       if (tmp - t1 >= 0){
            if (i == 0) cout << "2(0)";
            else if (i == 1) cout << "2";
            else{
                cout << "2(";
                recursion(i);
                cout << ")";
            }
            tmp -= t1;
            if (tmp) cout << "+";
       }
    }
    return ;
}

int main(){
    cin >> n;
    recursion(n);
    return 0;
}