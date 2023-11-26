#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, sum, ptr, cnt = 2;
long long ans[1000000];
int que[100000];

// 我就搞不懂了，这么小小的一道题目，用vector竟然全错，手动写数组竟然能对。

int main(){
    cin >> n;
    if (n < 5) {
        cout << n << endl;
        return 0;
    }
    while(sum < n){
        que[ptr++] = cnt;
        sum += cnt;
        cnt += 1;
    }
    que[sum-n-2] = 0;

    long long p = 1, c = 0;
    ans[1] = 1;
    for (int i=0; i<ptr; i++){
        int j = 0;
        if (!que[i]) continue;
        cout << que[i] << " ";
        for (j=1; j<=p; j++){
            ans[j] = ans[j]*que[i] + c;
            c = ans[j] / 10;
            ans[j] %= 10;
        }
        while(c > 0){
            ans[j] = c % 10;
            c /= 10;
            j++;
        }
        p = j - 1;
    }
    cout << endl;
    bool flag = 1;
    for (int i=p; i>=1; i--){
        if (flag && ans[i] == 0){
            continue;
        } else flag = 0;
        cout << ans[i];
    }
    return 0;
}