#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int k, m;
int vis[100000005];
string ans;

struct node{
    int a;
    bool friend operator < (node a, node b){
        return a.a > b.a;
    }
};
priority_queue<node> que;

inline string convert(int num){
    string s;
    while(num){
        s += (num % 10) + '0';
        num /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

void bfs(){
    que.push((node){1});
    vis[1] = 1;
    while(!que.empty()){
        node t = que.top();
        ans += convert(t.a);
        if (que.size() == k) return ;
        que.pop();
        int a = t.a * 2 + 1;
        if (vis[a] == 0){
            vis[a] = 1;
            que.push((node){a});
        }
        int b = t.a * 4 + 5;
        if (vis[b] == 0){
            vis[b] = 1;
            que.push((node){b});
        }
    }
    return ;
}

void del(){
    // 删除递增数列的第一个数字。
    while(m--){
        int len = ans.size();
        bool flag = false;
        for (int i=0; i<len; i++){
            if (ans[i] < ans[i+1]){
                ans = ans.substr(0, i) + ans.substr(i+1, len-i);
                flag = 1;
                break;
            }
        }
        if (flag == false) ans = ans.substr(0, len-1);
        // cout << ans << endl;
    }
    return ;
}

int main(){
    cin >> k >> m;
    bfs();
    cout << ans << endl;
    del();
    cout << ans << endl;
    return 0;
}