#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, sum;

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        int t;
        cin >> t;
        sum ^= t;
    }  
    cout << sum << endl; 
    return 0;
}