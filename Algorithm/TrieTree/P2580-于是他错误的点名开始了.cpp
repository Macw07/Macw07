#include <iostream>
using namespace std;

// 字典树 Trie tree
/* 这几天跟树过不去了呢*/

const int MAXN = 1e6 + 5;
int trie[MAXN][65];
int vis[MAXN]; 
int n, m, depth;
string str;

int change(char c){
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
    return c - '0' + 52;
}

void insert(string str){
    int len = str.size();
    int root = 0;
    for (int i=0; i<len; i++){
        int t = change(str[i]);
        // 新建一个节点。
        if (trie[root][t] == 0){
            trie[root][t] = ++depth;
        }
        root = trie[root][t];
    }
    vis[root] = 1;
    return ;
}

int query(string str){
    int root = 0;
    int len = str.size();
    for (int i=0; i<len; i++){
        int t = change(str[i]);
        if (trie[root][t] == 0) {
            return 0;
        }
        root = trie[root][t];
    }
    if (vis[root] == 1){
        vis[root] += 1;
        return 1;
    } else if (vis[root] > 1) return 2;
    return 0;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> str;
        insert(str);
    }
    cin >> m;
    for (int i=1; i<=m; i++){
        cin >> str;
        int t = query(str);
        if (t == 1) cout << "OK" << endl;
        else if (t == 2) cout << "REPEAT" << endl;
        else cout << "WRONG" << endl;
    }

    return 0;
}