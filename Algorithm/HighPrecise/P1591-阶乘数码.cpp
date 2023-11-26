#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// 一道模拟和高精度的题目

int ans[1000000];

int main(){
    int t, n, a, p, c;
    cin >> t;
    // 高精度乘上低精度
    while(t--){
        cin >> n >> a;
        p = 1, c = 0;
        memset(ans, 0, sizeof ans);
        ans[1] = 1;
        for (int i=2; i<=n; i++){
            int j = 0;
            for (j=1; j<=p; j++){
                ans[j] = i * ans[j] + c;
                c = ans[j] / 10;
                ans[j] = ans[j] % 10;
            } 
            while (c > 0){
                ans[j] = c % 10;
                c /= 10;
                j++; 
            }
            p = j-1;
        } 
        long long sum = 0;
        for (int i=1; i<=p; i++){
            if (ans[i] == a) sum ++;
        }
        cout << sum << endl;
    }
    return 0;
}