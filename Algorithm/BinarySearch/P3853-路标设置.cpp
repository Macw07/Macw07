#include <iostream>
#include <algorithm>
using namespace std;

int left_b = 0, right_b = 10000005;
int l, n, k, ans;
int arr[100005];

bool check(int mid){
    // 看一下答案是否可以被接受
    int cnt = 0;
    int steps = 0, ptr = 1;
    while (1){
        if (ptr <= n && arr[ptr]-steps <= mid) steps = arr[ptr++];
        else {
            steps += mid;
            cnt += 1;
        }
        if (steps >= l) break;
        if (cnt > k) return false;
    }
    return true;
}
int main(){
    scanf("%d %d %d", &l, &n, &k);
    for (int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }
    // 二分模板
    while(left_b <= right_b){
        int mid = (left_b+right_b) >> 1;
        if (check(mid)){
            ans = mid;
            right_b = mid - 1;
        } else left_b = mid + 1;
    }
    cout << ans << endl;
    return 0;
}