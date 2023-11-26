#include <iostream>
#include <cstring>
using namespace std;

int n, mod;
int arr[10005];
int vis[10005][500];
bool flag = 0;

int dfs(int c, int total){
    if (vis[c][total] != -1){
        return vis[c][total];
    }
    if(flag == 1){
        return 0;
    }
    if(c == n){
        // cout << total << endl;
        if(total % mod == 0){
            flag = 1;
        }
        return 0;
    }
    vis[c][total] = dfs(c+1, total + arr[c]);
    vis[c][total] = dfs(c+1, total - arr[c]);
    return vis[c][total];
}

int main(){
    cin >> n >> mod;
    memset(vis,-1,sizeof(vis));
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    dfs(0, 0);
    if (flag == 1){
        cout << "Divisible" << endl;
    } else{
        cout << "Not divisible" << endl;
    }
    return 0;
}