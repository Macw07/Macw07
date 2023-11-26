#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, total;

void recursion(int number){
    total += 1;
    for (int i=1; i<=number/2; i++){
        recursion(i);
    }
    return ;
}

int main(){
    cin >> n;
    recursion(n);
    cout << total << endl;
    return 0;
}