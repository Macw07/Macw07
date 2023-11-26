#include <iostream>
#include <queue>
using namespace std;

int n, k, ans, current;
int color[50005];
queue<int> que;

int main(){
    // freopen("data/textcase020.in", "r", stdin);
    // freopen("data/textcase020.out", "w", stdout);
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        int t; cin >> t;
        if (que.size() == k){
            int tail = que.front();
            que.pop();
            color[tail]--;
            if (!color[tail]) current--;
        }
        if (!color[t]) current++;
        color[t]++;
        que.push(t);
        ans = max(ans, current);
    }
    cout << ans << endl;
    return 0;
}