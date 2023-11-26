#include <iostream>
#include <algorithm>
using namespace std;

int n;
string arr[505];

bool cmp(string a, string b){
    // 这道题考的竟然不是字符串的处理，原来仅仅只是单纯的字符串比较。
    // 考虑一下哪两个数相加更优即可（贪心算法）
    return a + b > b + a;
}

int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n, cmp);
    string ans = "";
    for (int i=0; i<n; i++){
        ans += arr[i];
    }
    cout << ans << endl;
    return 0;
}