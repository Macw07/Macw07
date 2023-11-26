#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

int total = 0;
int n, vis[30];
string arr[30];
unordered_map<string, int> map;

// 这个单词选不选
void dfs(int k, int wordcount, string str){
    if (wordcount == 26) {
        if (!map.count(str)){
            map[str] = 1;
            total += 1;
            // cout << str << endl;
        }
    }
    if (k > n) return ;

    // 选这个单词
    int wc = wordcount;
    for (int i=0; i<arr[k].size(); i++){
        if (arr[k][i] < 'a' && arr[k][i] > 'z') continue;
        if (!vis[arr[k][i]-'a']) wc++;
        vis[arr[k][i]-'a'] += 1;
    }
    dfs(k+1, wc, str + arr[k]);
    for (int i=0; i<arr[k].size(); i++) vis[arr[k][i]-'a'] -= 1;

    // 不选这个单词
    dfs(k+1, wordcount, str);
    return ;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    dfs(1, 0,  "");
    cout << total << endl;
    return 0;
}