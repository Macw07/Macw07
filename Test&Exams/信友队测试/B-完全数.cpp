#include <iostream>
#include <algorithm>
using namespace std;

int n;

bool check(int k){
    int sum = 0;
    for (int i=1; i<k; i++){
        if (k % i == 0) sum += i;
    }
    return sum == k;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        if (check(i)){
            cout << i << endl;
        }
    }
    return 0;
}