#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000005];
int n, m;
int l, r;

// m指代的是高度,判断这个高度能否满足所需的木材m;
bool check(int h){
    int sum = 0;  // 累加判断
    for (int i=0; i<n; i++){
        sum += max(arr[i] - h, 0);  // 如果树可以砍下来
        if (sum >= m){
            return true;  // 砍下来的树木足够了
        }
    }
    return sum >= m;  // 砍下来的树木不够
}

int main(){
    cin >> n >> m;
    int maximum=0;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        maximum = max(arr[i], maximum);
    }
    // 二分查找,找出最大的高度
    l = -1, r=maximum;
    int ans=0;
    while(l+1 != r){
        int h = (l+r)/2;
        if (check(h)){
            // 如果高度足够了,升高高度
            l = h;
            ans = max(ans, l);
        } else{
            // 否则降低高度
            r = h;
        }
    }
    cout << ans << endl;
    return 0;
}