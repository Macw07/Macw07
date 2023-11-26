#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, arr[555], now_depth = 1, sum;
int ans_depth = -0x7f;
int max_num = -0x7f;

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    int i = 1;
    while (i <= n){
        sum = 0;
        for (; i<pow(2, now_depth); i++) {
            // cout << arr[i] << ' ';
            sum += arr[i];
            if (i > n + 50) break;
        }
        // cout << endl << sum << endl << endl;
        if (sum > max_num){
            max_num = sum;
            ans_depth = now_depth;
        }
        now_depth += 1;
    }
    cout << ans_depth << endl;
    return 0;
}