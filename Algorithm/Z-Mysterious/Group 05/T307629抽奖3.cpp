#include <iostream>
#include <algorithm>
using namespace std;

// 减少枚举的数量

int arr[10005];
int cnt[1005];

int main(){
    long long n, t, total=0;
    cin >> n >> t;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    // 进行抽奖
    for (int i=0; i<n; i++){
        if (arr[i] > t) continue;
        for (int j=0; j<n; j++){
            if (arr[j] > t || arr[i]+arr[j] > t) continue;
            total += cnt[t-arr[i]-arr[j]];
        }
    }
    cout << total << endl;
    return 0;
}