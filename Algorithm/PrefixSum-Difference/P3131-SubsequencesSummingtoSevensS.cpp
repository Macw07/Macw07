#include <iostream>
using namespace std;

int n, ans;
int prefix[50005];
int vis[50005];

int main(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        int t;
        scanf("%d", &t);
        prefix[i] = (prefix[i-1] + t) % 7;
        if (prefix[i] == 0){
            ans = max(ans, i);
            continue;
        }
        if (vis[prefix[i]] == 0){
            vis[prefix[i]] = i;
        } else{
            int diff =  i - vis[prefix[i]];
            ans = max(ans, diff);
        }
    }
    cout << ans << endl;
    return 0;
}