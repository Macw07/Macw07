#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = 0;
int fish[1005], petrol[1005];

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> fish[i] >> petrol[i];
    }
    ans = fish[0];  // 第一站必须花钱
    for (int i=1; i<n; i++){
        // 直接进行模拟把，考虑买或者存。
        // 情况： 第一站只能买，到了第二站进行比对，如果第二站购买的价格比第一站购买的价格+第一站的钱贵，购买第一站的，否则购买第二站的，以此类推。
        // 到了第三站以后，需要判断之前的每一站
        int previous = 0x7f7f7f7f;
        for (int j=0; j<i; j++){
            int temp = fish[j];
            for (int k=j; k<i; k++){
                temp += petrol[k];
            }
            previous = min(previous, temp);
        }
        ans += min(previous, fish[i]);  // 前面的可能性以及直接购买当前站的花销的最小值
    }
    cout << ans << endl;
    return 0;
}