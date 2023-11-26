#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int k, len;
int arr[30];
int ans;
string s;

int main(){
    // freopen("6.in", "r", stdin);
    cin >> k >> s;
    len = s.size();
    for (int i=0; i<len; i++){
        arr[s[i]-'A'+1] += 1;
    }
    // for(int i=1; i<=26; i++){
    //     cout << arr[i] << " ";
    // }
    for (int i=1; i<=26; i++){
        bool flag = 0;
        int temp = k, total = arr[i];
        int l = i-1, r = i+1;
        while(1){
            if (temp != 0 && flag == 0 && l >= 1){
                flag = 1;
                // 看看最多能变换几个
                int max_t = temp / abs(i-l);
                if (temp != 0 && max_t >= arr[l]){
                    total += arr[l];
                    temp -= arr[l] * abs(i-l);
                    l -= 1;
                } else {
                    total += max_t;
                    temp -= max_t * abs(i-l);
                    break;
                }
            } 
            else if (temp != 0 && r <= 26){
                flag = 0;
                int max_t = temp / abs(i-r);
                if (max_t >= arr[r]){
                    total += arr[r];
                    temp -= arr[r] * abs(i-r);
                    r += 1;
                } else {
                    total += max_t;
                    temp -= max_t * abs(i-r);
                    break;
                }
            } else break;
            // cout << total << " " << temp << endl;
        }
        ans = max(ans, total);
    }
    cout << ans << endl;
    return 0;
}