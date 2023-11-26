#include <iostream>
using namespace std;

int n, ans;
int boys[100005], girls[100005];
int difference[100005];
int vis[200005];

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        int t;
        scanf("%d", &t);
        if (t == 1){
            boys[i] = boys[i-1] + 1;
            girls[i] = girls[i-1];
        } else{
            boys[i] = boys[i-1];
            girls[i] = girls[i-1] + 1;
        }
        difference[i] = boys[i]-girls[i];
        if (difference[i] == 0){
            ans = max(ans, i);
            continue;
        }
        if (vis[difference[i]+n] == 0){
            vis[difference[i]+n] = i;
        } else{
            int diff = i -  vis[difference[i]+n];
            ans = max(ans, diff);
        }
    }
    cout << ans << endl;
    return 0;
}