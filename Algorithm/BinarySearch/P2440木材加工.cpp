#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005];
int n, k, t=0;
int l, r;

// 答案的判断
bool check(int m){
    long long sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i] / m;
    }
    return sum >= k;
}

int main(){
    long long sum=0;
    int maxa = 0;
    cin >> n >> k;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
        maxa = max(arr[i], maxa);
    }
    // cout << maxa << endl;
    // 数据无效的判断
    if (sum < k){
        cout << "0" << endl;
        return 0;
    }
    // 开始二分法
    l = -1, r = maxa;
    while(l+1 != r){
        long m = (l+r)/2;
        // cout << m << " ";
        if (check(m)){
            l = m;
        } else{
            r = m;
        }
    }
    cout << l << endl;
    return 0;
}