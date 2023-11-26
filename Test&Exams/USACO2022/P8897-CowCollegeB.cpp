#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;
int n, k = 0x7f7f7f7f;
long long arr[MAXN];
long long ans;

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%lld", &arr[i]);
    sort(arr+1, arr+1+n, greater<int>());
    for (int i=1; i<=n; i++){
        long long current = i * arr[i];
        if (current > ans){
            ans = current;
            k = arr[i];
        } else if (current == ans && arr[i] < k) k = arr[i];
    }
    printf("%lld %d", ans, k);
    return 0;
}