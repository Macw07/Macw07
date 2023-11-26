#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int l, r=0;
int arr[100005];

bool check(int mid){
    // cout << mid << endl;
    // 每段的和不超过m
    int cut=1;
    int crt=0;
    for (int i=0; i<n; i++){
        if (crt + arr[i] <= mid){
            crt += arr[i];
        } else{
            crt = arr[i];
            cut++;
        }
    }
    return cut <= m;
}

int main(){
    cin >> n >> m;
    int total=0;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        r += arr[i];
        l = max(l, arr[i]);
    }
    // Binary Search
    // **注意:** 二分时的区间取值问题,很明显,对于l的赋值应该取数列中的最大值,(亲测,如果l赋值为0或1,第4个点会wa)
    int ans=total;
    while(l <= r){
        int mid = (l+r)/2; 
        if(!check(mid)){
            l = mid+1;
        } else{
            r = mid-1;
        }
    }
    cout << l << endl;
    return 0;
}