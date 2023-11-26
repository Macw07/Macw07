#include <iostream>
#include <algorithm>
using namespace std;

long long n, t;
long long di, bi;
struct node{
    long long di;
    long long bi;
};
long long ans;
long long remain;
node arr[100005];

long long min(long long a, long long b){
    if (a > b) return b;
    return a;
}

int main(){
    cin >> n >> t;
    for (int i=1; i<=n; i++){
        cin >> di >> bi;
        arr[i] = (node){di, bi};
    }
    arr[n+1] = ((node){0x7f7f7f7f7f7f, 0});
    for (int i=1; i<=n; i++){
        if (arr[i].di > t) break;
        long long nextDay = min(t, arr[i+1].di);
        // 在日起截止前吃得完
        if (nextDay - arr[i].di >= remain + arr[i].bi){
            ans += remain + arr[i].bi;
            remain = 0;
        }
        // 在日起截止前吃不完
        else{
            ans += nextDay - arr[i].di + 1;
            remain = remain + arr[i].bi - (nextDay - arr[i].di);
        }
        cout << ans << " " << remain << endl;
    }
    cout << ans << endl;
    return 0;
}