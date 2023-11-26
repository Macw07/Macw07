#include <iostream>
using namespace std;

char c;
const int MAXN = 1e9;
int n, p, ans;
int l = 0x7f7f7f7f, r;
short arr[MAXN + 5];

short max(short a, short b){
    if (a > b) return a;
    return b;
}

int main(){
    cin >> n;
    for (int j=1; j<=n; j++) {
        cin >> c >> p;
        if (c == 'L') {
            arr[0] += 1;
            arr[p+1] -= 1;
        } else {
            arr[p] += 1;
        }
    }
    for (int i=1; i<=100000; i++) {
        arr[i] += arr[i-1];
        ans = max(ans, arr[i]);
    }
    cout << n - ans << endl;
    return 0;
}