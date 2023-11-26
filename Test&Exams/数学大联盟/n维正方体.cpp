#include <iostream>
#include <cmath>
using namespace std;

bool check(int mid){
    return pow(2, mid-1)*mid >= 4980736;
}

int main(){
    int ans = 0, cnt = 0;
    int left = 0;
    int right = 30;
    while(left < right){
        int mid = (left+right) >> 1;
        cnt++;
        if (check(mid)){
            right = mid -1;
            ans = mid;
        } else{
            left = mid + 1;
        }
    }
    cout << ans << endl;
    cout << cnt << endl;
    return 0;
}