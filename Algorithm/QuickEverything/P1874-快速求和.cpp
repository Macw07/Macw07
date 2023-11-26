#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string str;
int target;
bool flag = false;
bool vis[105];

// 我真的服了，这么简单的一道dfs题目竟然做了这么多次才过。

void dfs(long long k, long long index){
    if (k == index){
        long long ans = 0, sum = str[0]-'0';
        for (int i=1; i<str.size(); i++){
            if (vis[i] == 0) sum = sum * 10 + str[i]-'0';
            else ans+=sum, sum=str[i]-'0';
        }
        ans += sum;
        if (ans == target) flag = true;
        return ;
    }
    for (int i=1; i<str.size(); i++){
        if (vis[i]) continue;
        vis[i] = 1;
        dfs(k+1, index);
        vis[i] = 0;
    }
    return ;
}

int main(){
    cin >> str >> target;
    for (int i=0; i<str.size(); i++){  // 判断i个加号是否可以组成这个数（记得从0开始）
        memset(vis, 0, sizeof vis);
        flag = false;
        dfs(0, i);
        if (flag == true){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}