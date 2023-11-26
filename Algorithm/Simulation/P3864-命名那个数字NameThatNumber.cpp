#include <iostream>
#include <map>
using namespace std;

// 服了，原谅我题没看清。

int n;
string target, tmp;
bool flag;
map<string, int> m;
char ans[15];
char arr[10][5];

void dfs(int dep){
    if (dep >= n){
        string str;
        for (int i=0; i<n; i++) str += ans[i];
        if (m.count(str)) {
            flag = 1;
            cout << str << endl;
        }
        return ;
    }
    for (int i=1; i<=3; i++){
        char t = arr[target[dep] - '0'][i];
        ans[dep] = t;
        dfs(dep + 1);
    }
    return ;
}

int main(){
    cin >> target;
    n = target.size();
    int i = 2, j = 1;
    for (int k=1; k<26; k++){
        if (char(k + 'A' - 1) == 'Q') continue;
        arr[i][j] = k + 'A' - 1;
        j += 1;
        if (j > 3) {
            j = 1;
            i += 1;
        }
    }
    for (int i=1; i<=4617; i++){
        cin >> tmp;
        m[tmp] += 1;
    }
    dfs(0);
    if (!flag) cout << "NONE" << endl;
    return 0;
}