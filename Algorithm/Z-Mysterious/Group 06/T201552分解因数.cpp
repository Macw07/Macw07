#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int ans = 0;

void decompose(int num, int div){
    if (num == 1){
        ans++;
        return;
    }
    for (int i=div; i<=num; i++){
        if (num % i == 0){
            decompose(num/i, i);
        }
    }
    return;
}

int main(){
    cin >> n;
    while(n--){
        cin >> k;
        ans = 0;
        decompose(k, 2);
        cout << ans << endl;
    }
    return 0;
}