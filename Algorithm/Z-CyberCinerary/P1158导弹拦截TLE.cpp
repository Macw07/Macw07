#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct location {
    int x, y;
};

int n, ans = 0x7f7f7f7f;
location sys1, sys2;
location arr1[100005];
location arr2[100005];

int dis(location a, location b){
    return pow((a.x-b.x), 2) + pow((a.y-b.y), 2);
}

bool cmp1(location a, location b){
    return dis(sys1, a) < dis(sys1, b);
}

bool cmp2(location a, location b){
    return dis(sys2, a) < dis(sys2, b);
}

int main(){
    cin >> sys1.x >> sys1.y >> sys2.x >> sys2.y;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr1[i].x >> arr1[i].y;
        arr2[i].x = arr1[i].x;
        arr2[i].y = arr1[i].y;
    }
    // 枚举不行，那就排序吧
    sort(arr1, arr1+n, cmp1);
    sort(arr2, arr2+n, cmp2);
    int dis1 = dis(sys1, arr1[n-1]);
    int dis2 = dis(sys2, arr2[n-1]);
    for (int i=0; i<=dis1 || i<=dis(sys1, arr2[n-1]); i++){
        for (int j=0; j<=dis(sys2, arr1[n-1]) || j<=dis2; j++){
            // 当sys1的半径为i，sys2的半径为j时，是否可以被同时覆盖。
            if (i < dis1 && j < dis(sys2, arr1[n-1])) continue;
            if (i < dis(sys1, arr2[n-1]) && j < dis2) continue;
            ans = min(ans, i+j);
        }
    }
    cout << ans << endl;
    return 0;
}