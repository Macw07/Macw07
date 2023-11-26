#include <iostream>
using namespace std;

int arr[1000005] = {};

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    int range = 0, distance = 0;  // 记录一下最远距离的下标
    int cnt = 0;
    bool flag = false;
    // 如果range一直是可以的情况下
    for (int i=0; i<=n; i++){
        range = max(range, arr[i]+i);  // 能跳的距离范围
        if (i == distance){  // 说明走到了最远距离，就不得不增加步数了
            if (distance != n-1){
                cnt++;
                distance = range;
                if (range > n){
                    flag = true;
                    break;
                }
            }
            
        }
    }
    if (flag == true) cout << cnt << endl;
    else cout << 0 << endl;
    return 0;
}