#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define int long long
#define double long double

int n, m, ans;
double x, y, t;
struct node{
    int x;
    int y;
    int t;
} g[100005];

// double distance(double x1, double y1, double x2, double y2){
//     double tmp = (y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1);
//     return (double)sqrt(tmp);
// }

inline bool cmp(node a, node b){ return a.t < b.t; }

signed main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> g[i].x >> g[i].y >> g[i].t;
    sort(g+1, g+1+n, cmp);
    while(m--) {
        cin >> x >> y >> t;
        int L = 1, R = n, k = 0;
        while(L <= R){
            int mid = (L + R) >> 1; 
            if (g[mid].t <= t) {
                L = mid + 1;
                k = mid;
            } else R = mid - 1;
        }
        double tmp;
        if (k == 0){
            tmp = sqrt((double)((x-g[k+1].x)*(x-g[k+1].x) + (y-g[k+1].y)*(y-g[k+1].y)));
            if (tmp > (g[k+1].t - t)) ans += 1;
        } else if (k == n){
            tmp = sqrt((double)((x-g[k].x)*(x-g[k].x) + (y-g[k].y)*(y-g[k].y)));
            if (tmp > (t - g[k].t)) ans += 1;
        } else{
            int cnt = 0;
            tmp = sqrt((double)((x-g[k+1].x)*(x-g[k+1].x) + (y-g[k+1].y)*(y-g[k+1].y)));
            if (tmp > (g[k+1].t - t)) cnt += 1;
            tmp = sqrt((double)((x-g[k].x)*(x-g[k].x) + (y-g[k].y)*(y-g[k].y)));
            if (tmp > (t - g[k].t)) cnt += 1;

            if (cnt) ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}