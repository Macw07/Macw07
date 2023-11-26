#include <iostream>
using namespace std;

int n, k, m;
int arr[5050];

int main(){
    // freopen("testcase002.in", "r", stdin);
    // freopen("testcase012.out", "w", stdout);
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
    while(k--){
        cin >> m;
        // 计算总价
        int total = 0, t;
        for (int i=1; i<=m; i++){
            cin >> t;
            total += arr[t];
            arr[t] = -1;
        }
        cout << total << " ";

        // 重新排序
        int left = 1;
        int right = 1;
        while(left <= n - m){
            if (arr[left] != -1) left++;
            else{
                // 从右边找到第一个符合条件的。
                right = left;
                while(right <= n && arr[right] == -1) right++;
                arr[left] = arr[right];
                arr[right] = -1;
                left++; right++;
            }
        }
        n -= m;
    }
    return 0;
}