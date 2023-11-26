#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const long MAXN = 1e5;
const long MAXL = 1e7;
long T;
long n, k, maxi;
long low[MAXN+5], high[MAXN+5];
vector<long> diff(MAXL+5);
vector<long> prefix(MAXL+5);

signed main(){
    cin >> T;
    while(T--){
        cin >> n >> k;
        for (int i=1; i<=MAXL; i++) diff[i] = 0;
        maxi = -0x7f7f7f7f;
        // WTF，这里应该是前缀和和差分。
        for (long i=1; i<=n; i++) {
            cin >> high[i];
            if (high[i] > maxi) maxi = high[i];
        }
        for (long i=1; i<=n; i++) {
            cin >> low[i];
            diff[low[i]] += 1;
            diff[high[i]] -= 1;
        }
        for (long i=1; i<maxi; i++) {
            diff[i] = diff[i-1] + diff[i];
            prefix[i] = prefix[i-1] + diff[i];
        }

        // WTF，这里应该是倍增。
        // bool flag = 1;
        // for (long i=0; i<maxi&&flag; i++){
        //     long start = i, len = 1;
        //     while(len){
        //         if ((start + len) <= maxi && prefix[start+len]-prefix[i] <= k){
        //             if (prefix[start+len]-prefix[i] == k){
        //                 cout << i+1 << " " << start+len+1 << endl;
        //                 flag = 0;
        //                 break;
        //             }
        //             start += len;
        //             len <<= 1;
        //         } else (len >>= 1);
        //     }
        // }
        // if (flag) cout << "IMPOSSIBLE\n";

        bool flag = 1;
        for (int i=0; i<maxi&&flag; i++){
            for (int j=i+1; j<maxi&&flag; j++){
                long sum = prefix[j] - prefix[i];
                if (sum == k){
                    flag = 0;
                    cout << i+1 << " " << j+1 << endl;
                    break;
                }
            }
        }
        if (flag) cout << "IMPOSSIBLE\n";
    }   
    return 0;
}