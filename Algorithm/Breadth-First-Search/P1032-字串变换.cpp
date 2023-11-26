#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

// 这道题需要使用 unordered_map这个东西，不然直接查找字符串是否重复的话会浪费非常多的时间，
// 就连我自己的电脑也跑了好几秒，oj肯定会tle的。

struct rule{string a; string b; };
struct node{
    string str;
    int steps;
};
string sa, sb;
string t1, t2;
rule rules[10];
unordered_map<string, int> vis;
int r = 0;
queue<string> que;

int search(int index, string a, string b, string c){
    // 在string a中查找string b
    int flag = -1;
    string ans = "";
    for (int i=0; i<a.size(); i++){
        if (i >= index && a[i] == b[0] && flag == -1){
            string s;
            for (int j=i; j<i+b.size(); j++){
                s += a[j];
            }
            if (s == b){
                flag = i;
                ans += c;
                i += b.size();
            };
        }
        if (a[i]) ans += a[i];
    }
    if (flag != -1 && !vis.count(ans)){
        que.push(ans);
        vis[ans] = vis[que.front()]+1;
    }
    if (flag != -1) return flag;
    return -1; 
}

void bfs(){
    vis[sa] = 0;
    que.push(sa);
    while(!que.empty()){
        string t = que.front();
        if (t == sb && vis[t] <= 10){
            cout << vis[t] << endl;
            return;
        }
        if (vis[t] > 10) break;
        // 根据不同的方式替换查找
        for (int i=0; i<r; i++){
            // 查找 + 替换
            int index = -1;
            while(true){
                index = search(index+1, t, rules[i].a, rules[i].b);
                if (index == -1) break;
            }
        }
        que.pop();
    }
    cout << "NO ANSWER!" << endl;
    return;
}

int main(){
    cin >> sa >> sb;
    while(cin >> t1 >> t2){
        if (t1 == "1" && t2 == "1") break;
        rules[r++] = (rule){t1, t2}; 
    }
    bfs();
    return 0;
}