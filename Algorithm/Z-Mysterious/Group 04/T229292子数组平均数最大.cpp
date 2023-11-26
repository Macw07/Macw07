#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000000];

int main(){
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    // 双指针滑动窗口
    long long m=0, temp=0;
    for (int i=0; i<k; i++){
        temp += arr[i];
        m = max(m, temp);
    }
    for (int i=k; i<n; i++){
        temp = temp-arr[i-k]+arr[i];
        m = max(m, temp);
    }
    // cout << m << endl;
    double ans = double(m)/k;
    printf("%.2f\n", ans);
    return 0;
}
