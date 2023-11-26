#include <iostream>
#include <algorithm>
using namespace std;

int ll, rr, pre;
bool flag = 0;
int n, arr[350];
long long sum = 0;

int main(){
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    // 贪心思路：第一次跳最高点，第二次跳最低点。
    sort(arr, arr+n);  // 这里需要+1因为我们需要把起始点算上。
    ll = 0, rr = n-1;
    pre = 0;
    for (int i=0; i<n; i++){
        if (flag == 0) {
            sum += (arr[rr]-pre)*(arr[rr]-pre); 
            pre = arr[rr]; rr--;
        }
        else {
            sum += (arr[ll]-pre)*(arr[ll]-pre); 
            pre = arr[ll]; ll++;
        }
        flag = !flag;
    }
    cout << sum << endl;
    return 0;
}