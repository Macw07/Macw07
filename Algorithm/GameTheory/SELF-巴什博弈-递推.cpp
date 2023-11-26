#include <iostream>
using namespace std;

int main(){
    int n;
    bool arr[10005] = {0, 1, 1, 1, 1};
    cin >> n;
    for (int i=5; i<=n; i++){
        int total = 0;
        // 遍历所有拿的情况。
        for (int j=1; j<=4; j++) total += arr[i-j];
        // 只能变成N-Position，则当前一定是P-Position。
        if (total == 4) arr[i] = 0;
        else arr[i] = 1; // 否则就是N-Position。
    }
    if (arr[n] == 0) cout << "Defeat" << endl;
    else cout << "Victory" << endl;
    return 0;
}