#include <iostream>
#include <algorithm>
using namespace std;

// 可恶，居然使用的是平面直角坐标系的第一象限。
typedef long long ll;

ll n, m, ans = 0x7f7f7f7f;
string npath;
string mpath;
ll fx, fy;
ll cx, cy;
ll dx[] = {0, 1, 0, -1};
ll dy[] = {1, 0, -1, 0};

inline ll direction(char c){
    if (c == 'N') return 0;
    if (c == 'E') return 1;
    if (c == 'S') return 2;
    return 3;
}

inline ll max(ll a, ll b){
    if (a > b) return a;
    return b;
}

inline ll distance(ll fx, ll fy, ll cx, ll cy){
    return (fx-cx) * (fx-cx) + (fy - cy) * (fy - cy);
}

inline bool isvalid(ll x, ll y){
    return (x >= 0 && x <= 1000 && y >= 0 && y <= 1000);
}

void recursion(ll fx, ll fy, ll cx, ll cy, ll a, ll b, ll total){
    if (total >= ans) return ;
    if (a >= n && b >= m){
        ans = min(ans, total);
        return ;
    }

    ll fx_n = fx + dx[direction(npath[a])];
    ll fy_n = fy + dy[direction(npath[a])];
    ll cx_n = cx + dx[direction(mpath[b])];
    ll cy_n = cy + dy[direction(mpath[b])];

    // 牛走人不走
    if (b < m){
        recursion(fx, fy, cx_n, cy_n, a, b+1, total + distance(fx, fy, cx_n, cy_n));
    }
    
    // 人走牛不走
    if (a < n){
        recursion(fx_n, fy_n, cx, cy, a+1, b, total + distance(fx_n, fy_n, cx, cy));
    }

    // 人走牛也走
    if (a<n && b<m){
        recursion(fx_n, fy_n, cx_n, cy_n, a+1, b+1, total + distance(fx_n, fy_n, cx_n, cy_n));
    }
    return ;
}

int main(){
    cin >> n >> m;
    cin >> fx >> fy >> cx >> cy;
    cin >> npath >> mpath;
    recursion(fx, fy, cx, cy, 0, 0, 0);
    cout << ans << endl;
    return 0;
}