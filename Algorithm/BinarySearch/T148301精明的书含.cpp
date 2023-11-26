#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[10005];
int l=0, r=0;

// mid元一组,能否分出来
bool check(int mid){
    int count=1, now=0;
    for (int i=0; i<n; i++){
        if (now + arr[i] < mid){
            now += arr[i];
        } else{
            count++;
            now = arr[i];
        }
    }
    return count <= m;
}

int main(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        l = max(arr[i], l);
        r += arr[i];
    }
    // cout << check(10) << endl;
    // 进行二分查找
    while(l+1 != r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid;
        } else{
            l = mid;
        }
    }
    cout << l << endl;
    return 0;
}