#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// 最小的两个质数的乘积
int n, q, t;
int arr[100005];

int main(){
    cin >> n;
    while(n--){
        cin >> q;
        t = 0;
        int m = sqrt(q);
        // 质因数分解。
        for(int i=2; i<=m; i++){
            while(q%i==0&&q!=i){
                arr[++t] = i;
                q /= i;
                if (t >= 2) break;
            }
            if (t >= 2) break;
        }
        if (t == 0) cout << 1 << endl << 0 << endl;
        else if (t == 1) cout << 2 << endl;
        else cout << 1 << endl << arr[1] * arr[2] << endl;
    }
    return 0;
}