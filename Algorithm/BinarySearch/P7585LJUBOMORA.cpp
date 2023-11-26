#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long n, m, mid;
long long l=1, r=0;
long long arr[300005];

bool check(long long mid){
    long long total=0;
    for (int i=0; i<m; i++){
        total += ceil(double(arr[i])/mid);
    }
    // cout << total << endl;
    return total <= n;
}
int main(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
        cin >> arr[i];
        r += arr[i];
    }
    // cout << check(3) << endl;
    while(l+1 != r){
        mid = (l+r)/2;
        // cout << l << " " << r << endl;
        if(check(mid)){
            r = mid;
        } else{
            l = mid;
        }
    }
    cout << r << endl;
    return 0;
}