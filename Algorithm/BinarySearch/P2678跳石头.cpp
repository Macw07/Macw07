#include <iostream>
#include <algorithm>
using namespace std;

int length, n, m;
int arr[50005];
int l, r;

bool check(int mid){  // 判断当最小值为m的时候能否到达
    int count=0;
    int now = arr[0];
    for (int i=1; i<=n+1; i++){  // 这里的n+1是因为还有最后一个石子
        if (arr[i] - now < mid){
            count++;
        } else{
            now = arr[i];
        }
    }
    return count <= m;  // 判定移除石子后是否可以
}

int main(){
    cin >> length >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
    arr[0] = 0;
    arr[n+1] = length;
    // 二分法查找答案
    l=-1, r=100000000;
    int ans=0;
    while(l+1 != r){
        int mid = (l+r)/2;
        if (check(mid)){
            l = mid;
            ans = max(ans, l);
        } else{
            r = mid;
        }
    }
    cout << ans;
    return 0;
}