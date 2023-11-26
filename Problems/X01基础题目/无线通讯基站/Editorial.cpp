#include <iostream>
using namespace std;

int n;
int arr[105];
int ans_len, ans_begin;

int main(){
    // freopen("testcase005.in", "r", stdin);
    // freopen("testcase005.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    // 从第i个数字开始尝试。
    for (int i=1; i<=n; i++){
        // 尝试公差为j所能构成的最长等差数列的长度。  
        int range = arr[n]-arr[i];
        for (int j=0; j<=range; j++){
            int len = 1, last = arr[i];

            for (int k=i+1; k<=n; k++){
                if (last + j == arr[k]){
                    len += 1;
                    last = arr[k];
                } else if (last + j < arr[k]) break;
            }

            if (len > ans_len){
                ans_len = len;
                ans_begin = i;
            }
        }
    }
    cout << ans_len << " " << ans_begin << endl;
    return 0;
}