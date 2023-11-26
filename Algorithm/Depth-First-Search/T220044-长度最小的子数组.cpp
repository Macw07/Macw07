#include <iostream>
#include <algorithm>
using namespace std;

int n, target;
int min_length = 0x7f7f7f7f;
int arr[100005], prefix[100005];

int main(){
    cin >> n >> target;
    for (int i=1; i<=n; i++) cin >> arr[i];

    // 前缀和优化
    for (int i=1; i<=n; i++) prefix[i] = prefix[i-1] + arr[i];

    for (int i=1; i<=n; i++){
        for (int j=i; j<=n; j++){
            if (prefix[j] - prefix[i-1] >= target){
                min_length = min(min_length, j-i+1);
                break;  // 记得加 break
            }
        }
    }
    if (min_length == 0x7f7f7f7f) cout << 0 << endl;
    else cout << min_length << endl;
    return 0;
}