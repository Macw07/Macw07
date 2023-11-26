#include <iostream>
#include <cmath>
using namespace std;

// 前缀和 + 倍增/二分 都可以AC。
int n, m;
long long t;
long long prefix[500005];

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%lld", &prefix[i]);
        prefix[i] = prefix[i-1] + prefix[i];
    }
    scanf("%d", &m);
    while(m--){
        scanf("%lld", &t);
        int start = 0, len = 1;
        while(len){
            if (start + len <= n && prefix[start+len] <= t){
                start += len;
                len <<= 1;
            } else len >>= 1;
        } 
        printf("%d\n", start);
    }
    return 0;
}