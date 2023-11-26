#include <iostream>
using namespace std;

int n, sum=0;

bool check(int n){
    while(n){
        int k = n%10;
        if (k == 2 || k == 0 || k == 1 || k == 9) return true;
        n /= 10;
    }
    return false;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        if (check(i)){
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}