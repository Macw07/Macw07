#include <iostream>
#include <algorithm>
using namespace std;

int n, k, l, r;
int maximum=0;
int arr[100005];

// check函数进行检查是否都可以被剪下来
bool check(double mid){
    int sum=0;
    for (int i=0; i<n; i++){
        sum += arr[i]/mid;
    }
    // cout << sum << endl;
    return sum>=k;
}
int main(){
    cin >> n >> k;
    for (int i=0; i<n; i++){
        double t;
        cin >> t;
        arr[i] = t*10000;
        maximum = max(arr[i], maximum);
    }
    // 通过二分答案法来找出答案
    l=-1, r=maximum;
    int ans=0;
    while(l+1 != r){
        int mid = (l+r)/2;
        // cout << mid << endl;
        if (mid==0) break;
        if(check(mid)){
            // 可以被剪下来:需要尝试更大的数
            l = mid;
            ans = max(ans, mid);
        } else{
            r = mid;
        }
    }
    printf("%.4f\n", double(ans)/10000);
    return 0;
}