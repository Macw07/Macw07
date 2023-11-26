#include <iostream>
using namespace std;

long long l, n, m, lb, rb;
long long arr[50005], ans;

bool check(long long mid){
    long long cnt = 0;
    long long last = 0;
    for (long long i=1; i<=n+1; i++){
        if (arr[i] - last < mid){
            // 拿走这一块荷叶。
            cnt += 1;
        } else{
            last = arr[i];
        }
    }
    return cnt <= m;
}

int main(){
    scanf("%lld %lld %lld", &l, &n, &m);
    arr[n+1] = l;
    for (long long i=1; i<=n; i++) {
        scanf("%lld", &arr[i]);
        rb += arr[i];
    }
    if (n == 0) {
        cout << l << endl;
        return 0;
    }
    while(lb <= rb){
        long long mid = (lb + rb) >> 1;
        // 当跳跃距离为mid时是否可行。
        if (check(mid)){
            lb = mid + 1;
            ans = mid;
        } else rb = mid - 1;  // 缩短跳跃距离。
    }
    cout << ans << endl;
    return 0;
}