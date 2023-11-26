#include <iostream>
#include <algorithm>
using namespace std;

long long w, n;
long long arr[30005];
long long l, r, total;

int main(){
    // freopen("mountains.in", "r", stdin);
    // freopen("mountains.out", "w", stdout);
    cin >> n >> w;
    for (int i=1; i<=n; i++) cin >> arr[i];
    sort(arr+1, arr+1+n);
    l = 1, r = n;
    long long current = 0;
    while(l <= r){
        // 先尝试放大的，大的放不下放小的。
        while(l <= r && current + arr[r] <= w){
            current += arr[r];
            r--;
        }
        while(l <= r && current + arr[l] <= w){
            current += arr[l];
            l++;
        }
        current = 0;
        total += 1;
    }
    cout << total << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}