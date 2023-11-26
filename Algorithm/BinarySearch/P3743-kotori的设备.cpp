#include <iostream>
#include <algorithm>
using namespace std;

double n, p;
double sum, ans;
double l=0, r=100000000000;

struct node{
    double a;
    double b;
}; 

node arr[100005];

// 我靠，这道题二分的检查很牛逼，拓展了我的新思路
bool check(double mid){
    double total = mid * p;  // 最多可以冲多少电。
    double sum = 0;  // 要用多少电
    for (int i=0; i<n; i++){
        if (arr[i].a*mid <= arr[i].b) continue;  
        sum += arr[i].a*mid - arr[i].b;
    }
    return sum <= total;
}

int main(){
    cin >> n >> p;
    for (int i=0; i<n; i++) {
        cin >> arr[i].a >> arr[i].b;
        sum += arr[i].a;
    }
    // 如果耗电速度小于充电速度，则不无论如何也用不完。
    if (sum <= p){
        cout << -1.0000000 << endl;
        return 0;
    }
    while (l < r){
        double mid = (l+r) / 2;
        if (check(mid)){
            ans = mid;
            l = mid + 0.00001;
        } else{
            r = mid - 0.00001;
        }
    }
    cout << ans << endl;
    return 0;
}