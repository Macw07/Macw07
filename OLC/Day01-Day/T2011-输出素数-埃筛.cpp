#include <iostream>
using namespace std;

int n;
int vis[10000005];

int main(){
    cin >> n;
    for (int i=2; i*i<=n; i++){
        if (vis[i]) continue;
        for (int j=i*i; j<=n; j+=i){
            vis[j] = 1;
        }
    }
    for (int i=2; i<=n; i++){
        if (!vis[i]) cout << i << " ";
    }
    return 0;
}