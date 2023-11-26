#include <iostream>
#include <cmath>
using namespace std;

int n, ans;
int pos, neg;
int arr[100005];
int diff[100005];

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
        diff[i] = arr[i] - arr[i-1];
    }
    for (int i=2; i<=n; i++){
        if (diff[i] > 0) pos += diff[i];
        else neg -= diff[i];  // 让负数以正数形式存储。
    }
    cout << max(pos, neg) << endl;
    cout << abs(pos-neg) + 1 << endl;
    return 0;
}

/*
7
3 3 2 2 1 3 2
*/