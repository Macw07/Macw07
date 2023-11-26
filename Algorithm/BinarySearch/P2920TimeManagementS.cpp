#include <iostream>
#include <algorithm>
using namespace std;
        
int n;
int l, r;

struct item{
    int t, s;
};
item arr[1005];

bool cmp(item a, item b){
    if (a.s != b.s){
        return a.s < b.s;
    }
    return a.t < b.t;
}

bool check(int m){
    int sum=m;
    for (int i=0; i<n; i++){
        sum += arr[i].t;
        if (sum > arr[i].s){
            return false;
        }
    }
    return sum <= arr[n-1].s;
}

int main(){
    int maximum=0;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i].t >> arr[i].s;
        maximum = max(arr[i].s, maximum);
    }
    sort(arr, arr+n, cmp);
    // check成功,可以二分. 
    // cout << check(3) << endl;
    l=-1, r=maximum;
    while(l+1 != r){
        int m = (l+r)/2;
        if(check(m)){
            l = m;
        } else{
            r = m;
        }
    }
    cout << l << endl;
    return 0;
}