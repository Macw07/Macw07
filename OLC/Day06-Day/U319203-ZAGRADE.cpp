#include <iostream>
#include <set>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

int len, cnt;
bool vis[205];  // vis[i]代表是否需要第i对括号。
int tmp[205];  // tmp[i]表示当str[i]为括号时，这是第几对括号。
string str;
set<string> s;
stack<int> stk;  // 记录每一组括号的坐标。

void dfs(int dep, string current){
    // 1代表选择第i个括号，0代表不选择。
    if (dep > cnt){
        string ans = "";
        for (int i=0; i<len; i++){
            if (str[i] == '(' || str[i] == ')'){
                if (current[tmp[i]] == '0') continue;
                else ans += str[i];
            } else ans += str[i];
        }
        s.insert(ans);
        return ;
    }
    
    // 选择这个括号或者不选择
    for (int i=dep-1; i<cnt; i++){
        if (vis[i]) continue;
        vis[i] = 1;
        dfs(dep + 1, current + "1");
        vis[i] = 0;
    }

    dfs(dep + 1, current + "0");
    return ;
}

int main(){
    cin >> str;
    len = str.length();
    for (int i=0; i<len; i++){
        char c = str[i];
        if (c == '('){
            stk.push(i);
        } else if (c == ')'){
            int k = stk.top();
            stk.pop();
            tmp[k] = cnt, tmp[i] = cnt;
            cnt++;
        }
    }

    // 暴力每一种组合
    dfs(1, "");

    for (set<string>::iterator it = s.begin(); it != s.end(); it++){
        if (*it == str) continue;
        cout << *it << endl;
    }
    return 0;
}