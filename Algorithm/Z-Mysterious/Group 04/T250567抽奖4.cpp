#include <iostream>
#include <algorithm>
using namespace std;

// 减少枚举的数量

long long cnt[105], arr[10005];
long long a, n, t;

// 面向结果编程
long long p1(){
    long long total = 0;
    sort(arr, arr+n);
    for (long long i=0; i<n; i++){
        if (arr[i] > t) break;
        for (long long j=0; j<n; j++){
            if (arr[j] > t || arr[i]+arr[j] > t) break;
            for (long long k=0; k<n; k++){
                if (arr[k] > t || arr[i]+arr[j]+arr[k] > t) break;
                total += cnt[t-arr[i]-arr[j]-arr[k]];
            }
        }
    }
    return total;
}

// 面向可能性编程
// 将一个数分成四个数
long long split(long long n){
    long long ans = 0;
    for (long long i=1; i<=n; i++){
        for (long long j=1; j<=n-i; j++){
            for (long long k=1; k<=n-i-j; k++){
                long long l = n - i - j- k;
                if (cnt[l] >= 1 && cnt[i] >= 1 && cnt[j] >= 1 && cnt[k] >= 1){
                    // prlong longf("%d %d %d %d\n", i, j, k, l);
                    long long crt = 1;
                    crt = cnt[i]*cnt[j]*cnt[k]*cnt[l];
                    ans+=crt;
                }
            }
        }
    }
    return ans;
}

int main(){
    scanf("%lld%lld", &n, &t);
    for (long long i=0; i<n; i++){
        scanf("%lld", &arr[i]);
        cnt[arr[i]]++;
    }
    // 进行抽奖
    cout << split(t) << endl;
    // cout << p1() << endl;
    // prlong longf("%d\n", total);
    return 0;
}