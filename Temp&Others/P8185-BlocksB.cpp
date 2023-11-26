#include <iostream>
#include <cstring>
using namespace std;

int n;
string ori[5];
string tmp;
bool flag;
string ans[5];
int vis[5];

bool aInb(char a, string b){
    for (int i=0; i<6; i++){
        if (b[i] == a) return true;
    }
    return false;
}

void dfs(int dep){
    if (dep >= 4){
        for (int i=0; i<tmp.size(); i++){
            if (!aInb(tmp[i], ans[i])) return ;
        }
        flag = true;
        return ;
    }
    for (int i=0; i<4; i++){
        if (vis[i]) continue;
        vis[i] = 1;
        ans[dep] = ori[i];
        dfs(dep + 1);
        vis[i] = 0;
    }
    return ;
}

int main(){
    cin >> n >> ori[0] >> ori[1] >> ori[2] >> ori[3];
    while(n--){
        flag = false;
        cin >> tmp;
        dfs(0);
        vis[0] = vis[1] = vis[2] = 0;
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}