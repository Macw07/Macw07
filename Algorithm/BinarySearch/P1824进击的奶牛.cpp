#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000010];
long n, c;
long l, r;
long ans=0;

bool check(long m){
    // cout << ":" << m << endl;
    int count=0, now=arr[0];
    for (int i=1; i<=n; i++){
        if (arr[i]-now >= m){
            count++;
            now = arr[i];
        }
    }
    // cout << ">" << count << endl;
    if (count+1 < c){
        return false;
    }
    return true;
}

int main(){
    cin >> n >> c;
    cin >> arr[0];
    for (int i=1; i<n; i++){
        cin >> arr[i];
    }
    // cout << maxi << "?" << endl;
    sort(arr, arr+n);
    // 二分查找
    l = -1, r=arr[n-1]-arr[0];
    while(l+1 != r){
        long m = (l+r)/2;
        if (check(m)){
            l = m;
            ans = max(ans, l);
        } else{
            r = m;
        }
        // cout << l << " " << r << endl;
    }
    cout << ans << endl;
    return 0;
}