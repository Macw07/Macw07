#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, d, ans = 1;
struct coordinate{
    double l, r;
} islands[1005];

inline bool cmp(coordinate a, coordinate b){
    return a.r < b.r;
}   

int main(){
    cin >> n >> d;
    for (int i=1; i<=n; i++) {
        int x, y;
        cin >> x >> y;
        if (y > d){
            cout << -1 << endl;
            return 0;
        }
        double dis = sqrt(d*d - y*y);  // 计算出x的左右边界极值。
        islands[i] = (coordinate){x - dis, x + dis};
    }
    sort(islands+1, islands+n+1, cmp);
    double now = islands[1].r;
    for (int i=2; i<=n; i++){
        if (now < islands[i].l){
            now = islands[i].r;
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}