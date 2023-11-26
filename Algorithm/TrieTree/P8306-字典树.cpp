#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 3e6;
int trie[MAXN][65];
int vis[MAXN];
int t, n, q;
int depth = 0;
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
        if (trie[root][t] == 0){
            trie[root][t] = ++depth;
        }
        root = trie[root][t];
        vis[root] += 1;
    }
    // vis[root] += 1;
    return ;
}

int query(string str){
    int len = str.size();
    int root = 0;
    for (int i=0; i<len; i++){
        int t = change(str[i]);
        if (trie[root][t] == 0){
            return 0;
        }
        root = trie[root][t];
    }
    return vis[root];
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> q;
        for (int i=0; i<=depth; i++){
            vis[i] = 0;
            for (int j=0; j<=64; j++){
                trie[i][j] = 0;
            }
        }
        depth = 0;
        for (int i=1; i<=n; i++){
            cin >> str;
            insert(str);
        }
        for (int j=1; j<=q; j++){
            cin >> str;
            int ans = query(str);
            cout << ans << endl;
        }
    }
    return 0;
}