#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 10005;
int trie[MAXN][26];
// count[i]节点i下面的所有子节点的字符总和。
int count[MAXN];
int depth = 0;
string str;

int convert(char c){
    if (c >= 'a' && c <= 'z') return c - 'a' + 1;
    return c - 'A' + 1;
}

void insert(string str){
    int root = 0;
    int len = str.size();
    for (int i=0; i<len; i++){
        if (str[i] == ' ') continue;
        int k = convert(str[i]);
        if (trie[root][k] == -1){
            depth += 1;
            trie[root][k] = depth;
        }
        root = trie[root][k];
    }
    return ;
}

int main(){
    for (int i=1; i<=5; i++){
        getline(cin, str);
        insert(str);
    }
    return 0;
}