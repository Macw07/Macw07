#include <iostream>
using namespace std;

bool isContain(int n){
    while (n){
        if (n % 7 == 0 || n % 10 == 7){
            return true;
        } else{
            n /= 10;
        }
    }
    return false;
}
int main(){
    int n;
    long long s=1;
    cin >> n;
    for (int i=2; i<=n; i++){
        if (isContain(i)){
            // cout << i << endl;
            continue;
        }
        s += i*i;
    }
    printf("%lld", s);
    return 0;
}