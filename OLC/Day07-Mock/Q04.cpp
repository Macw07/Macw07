#include <iostream>
#include <algorithm>
using namespace std;

string str;
int vis[15], ans;
bool flag = false;

void dfs(int dep, string crt){
    if (flag) return ;
    if (dep > 8){
        ans += 1;
        if (crt == str){
            flag = true;
        }
        return ;
    }
    for (int i=0; i<=9; i++){
        if (vis[i]) continue;
        vis[i] = 1;
        dfs(dep + 1, crt + char(i + '0'));
        vis[i] = 0;
    }
    return ;
}

int main(){
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    cin >> str;
    dfs(1, "");
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}