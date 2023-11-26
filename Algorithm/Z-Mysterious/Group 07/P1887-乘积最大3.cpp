#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int total = n % m;
    int ans = n / m;
    for (int i=total; i<m; i++){  // 输出 m 个数
        cout << ans << " ";
    }
    for (int i=0; i<total; i++){
        cout << ans + 1 << " ";
    }
    return 0;
}