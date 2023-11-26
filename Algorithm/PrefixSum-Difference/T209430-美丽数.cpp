#include <iostream>
using namespace std;

int n;
int prefix[100005];

bool isPretty(int k){
    int digits[10] = {};
    while(k){
        int c = k % 10;
        if (digits[c]) return 0;
        digits[c] = 1;
        k /= 10;
    }
    return 1;
}

int main(){
    cin >> n;
    for (int i=1; i<=100000; i++){
        prefix[i] = prefix[i-1] + isPretty(i);
    }
    while(n--){
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l-1] << endl;
    }
    return 0;
}