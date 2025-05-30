#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int n, m, t;
const int MAXN = 5e6 + 5;
bitset<1001> vis[MAXN];
int depth = 0;
int trie[MAXN][65];

int change(char c){
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
    return c - '0' + 52;
}

void insert(string str, int sen){
    int len = str.size();
    int root = 0;
    for (int i=0; i<len; i++){
        int t = change(str[i]);
        if (trie[root][t] == 0){
            trie[root][t] = ++depth;
        }
        root = trie[root][t];
    }
    vis[root][sen] = 1;
    return ;
}

void query(string str){
    int len = str.size();
    int root = 0;
    for (int i=0; i<len; i++){
        int t = change(str[i]);
        if (trie[root][t] == 0){
            cout << endl;
            return ;
        }
        root = trie[root][t];
    }
    for (int i=1; i<=n; i++){
        if (vis[root][i]){
            cout << i << " ";
        }
    }
    cout << endl;
    return ;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> t;
        string str;
        for (int j=1; j<=t; j++){
            cin >> str;
            insert(str, i);
        }
    }
    cin >> m;
    for (int i=1; i<=m; i++){
        string str;
        cin >> str;
        query(str);
    }
    return 0;
}