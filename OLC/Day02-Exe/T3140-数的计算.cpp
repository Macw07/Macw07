#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, total;

void recursion(int step, int number, long long crt){
    total += 1;
    for (int i=1; i<=number/2; i++){
        recursion(step+1, i, pow(10, step)*i + crt);
    }
    return ;
}

int main(){
    cin >> n;
    recursion(1, n, n);
    cout << total << endl;
    return 0;
}